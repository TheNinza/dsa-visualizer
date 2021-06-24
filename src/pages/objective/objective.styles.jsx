import { makeStyles } from "@material-ui/core";

export const useStylesObjective = makeStyles((theme) => ({
  root: {
    marginTop: "3rem",
    display: "flex",
    flexDirection: "column",
    alignItems: "center",
    marginLeft: "5rem",
    marginRight: "5rem",
    [theme.breakpoints.down("1000")]: {
      marginLeft: "2rem",
      marginRight: "2rem",
      marginTop: "2rem",
    },
  },
}));
