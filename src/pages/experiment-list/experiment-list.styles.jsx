import { makeStyles } from "@material-ui/core";

export const useStylesExperimentList = makeStyles((theme) => ({
  root: {
    marginTop: "3rem",
    marginLeft: "5rem",
    marginRight: "5rem",
    [theme.breakpoints.down("1000")]: {
      marginLeft: "2rem",
      marginRight: "2rem",
      marginTop: "2rem",
    },
  },

  listRoot: {
    width: "100%",
    // maxWidth: 360,
    backgroundColor: theme.palette.background.paper,
    boxShadow: "0 5px 8px rgb(0 0 0 / 10%)",
    borderRadius: "1rem",
    color: theme.palette.primary.dark,
  },
}));
