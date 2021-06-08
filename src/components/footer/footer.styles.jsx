import { makeStyles } from "@material-ui/core";

export const useStylesFooter = makeStyles((theme) => ({
  footer: {
    width: "100%",
    height: "20vh",
    background: theme.palette.background.paper,
    zIndex: 1500,
    color: theme.palette.text.primary,
    display: "block",
    bottom: 0,
  },
}));
