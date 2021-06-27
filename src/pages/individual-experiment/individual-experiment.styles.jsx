import { makeStyles } from "@material-ui/core";

export const useStylesIndividualExperiment = makeStyles((theme) => ({
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
  container: {
    width: "100%",
    boxShadow: "0 5px 8px rgb(0 0 0 / 20%)",
    borderRadius: "1rem",
    minHeight: "75vh",
    background: "white",
    marginTop: "2rem",
  },

  tabs: {
    background: "transparent",
    borderRadius: "1.5rem",
    boxShadow: "0 5px 8px rgba(0, 0, 0, 0.1)",
    [theme.breakpoints.down("1000")]: {
      borderRadius: "1rem",
    },
    [theme.breakpoints.down("880")]: {
      borderRadius: "0.8rem",
    },
  },
  tabIndicator: {
    display: "flex",
    justifyContent: "center",
    backgroundColor: "transparent",
    "& > span": {
      width: "70%",
      backgroundColor: theme.palette.secondary.main,
    },
  },
  newWraper: {
    flexDirection: "row",
    gap: "1rem",
  },

  selectedTab: {
    borderRadius: "1.5rem",
    background: "white",
    boxShadow: "0 5px 8px rgb(0 0 0 / 10%)",
    transition: "all 0.5s ease-in",
    [theme.breakpoints.down("1000")]: {
      borderRadius: "1rem",
    },
    [theme.breakpoints.down("880")]: {
      borderRadius: "0.8rem",
    },
  },
}));
