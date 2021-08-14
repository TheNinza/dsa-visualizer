import { makeStyles } from "@material-ui/core";

export const useStylesFeedback = makeStyles((theme) => ({
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
  feedbackInput: {
    width: "50%",
    [theme.breakpoints.down("800")]: {
      width: "100%",
    },
  },

  submitButton: {
    marginTop: "2rem",
    display: "block",
  },
}));
