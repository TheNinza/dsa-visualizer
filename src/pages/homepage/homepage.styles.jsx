import { makeStyles } from "@material-ui/core";

const drawerWidth = 240;

export const useStylesHomepage = makeStyles((theme) => ({
  root: {
    display: "flex",
  },
  drawer: {
    [theme.breakpoints.up("sm")]: {
      width: drawerWidth,
      flexShrink: 0,
    },
  },
  appBar: {
    zIndex: theme.zIndex.drawer + 1,
    background: theme.palette.background.default,
  },
  menuButton: {
    marginRight: theme.spacing(2),
    [theme.breakpoints.up("sm")]: {
      display: "none",
    },
  },
  // necessary for content to be below app bar
  toolbar: theme.mixins.toolbar,
  drawerPaper: {
    width: drawerWidth,
    height: "calc(100% - 20vh)",
  },
  content: {
    flexGrow: 1,
    padding: theme.spacing(3),
    minHeight: "80vh",
  },

  logo: {
    flexGrow: 1,
  },
}));
