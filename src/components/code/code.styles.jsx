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

    [theme.breakpoints.down("800")]: {
      flexDirection: "column",
      gap: "1rem",
    },
  },
  codeContainer: {
    maxWidth: 800,
    marginTop: "2rem",
    minHeight: "65vh",
  },
  notFound: {
    margin: "auto",
    textAlign: "center",
    lineHeight: "40vw",
  },
}));
