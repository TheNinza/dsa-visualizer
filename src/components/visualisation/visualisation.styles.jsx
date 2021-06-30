import { makeStyles } from "@material-ui/core";

export const useStylesVisualisation = makeStyles((theme) => ({
  root: {
    width: "100%",
    flex: 1,
    borderRadius: "1rem",
  },
  iframe: {
    width: "100%",
    height: 650,
    border: "none",
  },
}));
