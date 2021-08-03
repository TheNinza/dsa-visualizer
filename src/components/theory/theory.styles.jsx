import { makeStyles } from "@material-ui/core";

export const useStylesTheory = makeStyles((theme) => ({
  root: {
    width: "100%",
    flex: 1,
    borderRadius: "1rem",
  },
  markdownContainer: {
    color: theme.palette.text.primary,
  },
}));
