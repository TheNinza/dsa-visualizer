import { makeStyles } from "@material-ui/core";

export const useStylesNavbar = makeStyles((theme) => ({
  navbarRoot: {
    background: theme.palette.background.default,
    color: theme.palette.primary.main,
    height: "10vh",
    flexDirection: "row",
  },
  toolbar: {
    width: "100%",
    paddingLeft: "5rem",
    paddingRight: "5rem",
    [theme.breakpoints.down("1000")]: {
      paddingLeft: "2rem",
      paddingRight: "2rem",
    },
  },
  menuButton: {
    display: "none",
    [theme.breakpoints.down("1000")]: {
      display: "block",
    },
  },

  drawer: {
    display: "none",
    [theme.breakpoints.down("1000")]: {
      display: "unset",
    },
  },

  list: {
    width: 240,
  },

  navItemsContainer: {
    display: "flex",
    gap: "1.8rem",
    [theme.breakpoints.down("1270")]: {
      gap: "0.5rem",
    },
    [theme.breakpoints.down("1000")]: {
      display: "none",
    },
  },
  navItem: {
    // cursor: "pointer",
    fontSize: "1rem",
    [theme.breakpoints.down("1270")]: {
      fontSize: "0.8rem",
    },
  },
  listItem: {
    color: theme.palette.primary.main,
  },
}));
