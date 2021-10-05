import React from "react";
import PropTypes from "prop-types";
import AppBar from "@material-ui/core/AppBar";
import Toolbar from "@material-ui/core/Toolbar";
import CssBaseline from "@material-ui/core/CssBaseline";
import useScrollTrigger from "@material-ui/core/useScrollTrigger";
import Box from "@material-ui/core/Box";
import IconButton from "@material-ui/core/IconButton";
import MenuIcon from "@material-ui/icons/Menu";
import {
  Button,
  Drawer,
  List,
  ListItem,
  ListItemText,
} from "@material-ui/core";

import { useStylesNavbar } from "./navbar.styles";
import { useState } from "react";
import { useHistory } from "react-router-dom";

function ElevationScroll(props) {
  const { children } = props;
  const trigger = useScrollTrigger({
    disableHysteresis: true,
    threshold: 0,
  });

  return React.cloneElement(children, {
    elevation: trigger ? 4 : 0,
  });
}

ElevationScroll.propTypes = {
  children: PropTypes.element.isRequired,
};

const Navbar = (props) => {
  // reactRouter
  const history = useHistory();

  // styles
  const classes = useStylesNavbar();

  // local states
  const [drawerOpen, setDrawerOpen] = useState(false);

  // static data
  const navItems = ["Introduction", "List of experiments", "Feedback"];

  // custom functions
  const changeRoute = (text) => {
    const newRoute = text.toLowerCase().replace(/\s/g, "_");
    history.push(`/${newRoute}`);
  };

  return (
    <React.Fragment>
      <CssBaseline />
      <ElevationScroll {...props}>
        <AppBar position="sticky" classes={{ root: classes.navbarRoot }}>
          <Toolbar className={classes.toolbar} disableGutters={true}>
            <Box
              width="100%"
              display="flex"
              justifyContent="space-between"
              alignItems="center"
            >
              <img
                alt="logo"
                height="64x"
                src="/logo-dsa-adobe-svg.svg"
                onClick={() => changeRoute("")}
              />
              <Box className={classes.navItemsContainer}>
                {navItems.map((i) => (
                  <Button
                    onClick={() => changeRoute(i)}
                    key={i}
                    color="primary"
                    className={classes.navItem}
                  >
                    {i}
                  </Button>
                ))}
              </Box>
            </Box>
            <IconButton
              color="inherit"
              aria-label="open drawer"
              edge="start"
              onClick={() => setDrawerOpen(true)}
              className={classes.menuButton}
            >
              <MenuIcon />
            </IconButton>
          </Toolbar>
        </AppBar>
      </ElevationScroll>
      <Drawer
        className={classes.drawer}
        open={drawerOpen}
        onClose={() => setDrawerOpen(false)}
      >
        <List className={classes.list}>
          {navItems.map((text) => (
            <ListItem
              button
              key={text}
              onClick={() => changeRoute(text)}
              className={classes.listItem}
            >
              <ListItemText primary={text} />
            </ListItem>
          ))}
        </List>
      </Drawer>
    </React.Fragment>
  );
};

export default Navbar;
