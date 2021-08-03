import { makeStyles } from "@material-ui/core";

export const useStylesCode = makeStyles((theme) => ({
  root: {
    width: "100%",
    flex: 1,
    borderRadius: "1rem",
  },
  tabThemeContainer: {
    display: "flex",
    justifyContent: "space-between",
    gap: "2rem",
  },
  codeContainer: {
    maxWidth: 800,
    marginTop: "2rem",
  },
}));
