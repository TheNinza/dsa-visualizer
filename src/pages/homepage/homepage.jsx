import React, { useState } from "react";
import PropTypes from "prop-types";
import AppBar from "@material-ui/core/AppBar";
import CssBaseline from "@material-ui/core/CssBaseline";
import Divider from "@material-ui/core/Divider";
import Drawer from "@material-ui/core/Drawer";
import Hidden from "@material-ui/core/Hidden";
import IconButton from "@material-ui/core/IconButton";
import List from "@material-ui/core/List";
import ListItem from "@material-ui/core/ListItem";
import ListItemText from "@material-ui/core/ListItemText";
import MenuIcon from "@material-ui/icons/Menu";
import Toolbar from "@material-ui/core/Toolbar";
import Box from "@material-ui/core/Box";
import Button from "@material-ui/core/Button";
import { makeStyles, useTheme } from "@material-ui/core/styles";
import { Route, Switch, useHistory } from "react-router";
import HomePageIntroduction from "../../components/homepage-introduction/homepage-introduction";
import { useStylesHomepage } from "./homepage.styles";

const HomePage = (props) => {
  const { window } = props;
  const classes = useStylesHomepage();
  const theme = useTheme();
  const [mobileOpen, setMobileOpen] = useState(false);

  // routing
  const history = useHistory();

  const handleDrawerToggle = () => {
    setMobileOpen(!mobileOpen);
  };

  const changeRoute = (text) => {
    const newRoute = text.toLowerCase().replace(/\s/g, "_");
    history.push(`/${newRoute}`);
  };

  // static data
  const navItems = [
    "Introduction",
    "Objective",
    "List of experiments",
    "Target Audience",
    "Course Alignment",
    "Feedback",
  ];

  const drawer = (
    <div>
      <div className={classes.toolbar} />
      <Divider />
      <List>
        {navItems.map((text, index) => (
          <ListItem button key={text} onClick={() => changeRoute(text)}>
            <ListItemText primary={text} />
          </ListItem>
        ))}
      </List>
    </div>
  );

  const container =
    window !== undefined ? () => window().document.body : undefined;

  return (
    <div className={classes.root}>
      <CssBaseline />
      <AppBar position="fixed" className={classes.appBar}>
        <Toolbar>
          <IconButton
            color="inherit"
            aria-label="open drawer"
            edge="start"
            onClick={handleDrawerToggle}
            className={classes.menuButton}
          >
            <MenuIcon color="primary" />
          </IconButton>
          <Box className={classes.logo} color="textPrimary" component="div">
            <img
              alt="logo"
              height="56"
              src="https://www.iiitm.ac.in/templates/shaper_educon/images/presets/preset1/logo@2x.png"
            />
          </Box>
          <Button onClick={() => changeRoute("")} color="primary">
            Home
          </Button>
        </Toolbar>
      </AppBar>
      <nav className={classes.drawer} aria-label="mailbox folders">
        {/* The implementation can be swapped with js to avoid SEO duplication of links. */}
        <Hidden smUp implementation="css">
          <Drawer
            container={container}
            variant="temporary"
            anchor={theme.direction === "rtl" ? "right" : "left"}
            open={mobileOpen}
            onClose={handleDrawerToggle}
            classes={{
              paper: classes.drawerPaper,
            }}
            ModalProps={{
              keepMounted: true, // Better open performance on mobile.
            }}
          >
            {drawer}
          </Drawer>
        </Hidden>
        <Hidden xsDown implementation="css">
          <Drawer
            classes={{
              paper: classes.drawerPaper,
            }}
            variant="permanent"
            open
          >
            {drawer}
          </Drawer>
        </Hidden>
      </nav>
      <main className={classes.content}>
        <div className={classes.toolbar} />
        <Switch>
          <Route path="/" exact component={HomePageIntroduction} />
        </Switch>
        <Switch>
          <Route path="/introduction" exact component={HomePageIntroduction} />
        </Switch>
      </main>
    </div>
  );
};

HomePage.propTypes = {
  /**
   * Injected by the documentation to work in an iframe.
   * You won't need it on your project.
   */
  window: PropTypes.func,
};

export default HomePage;
