import { makeStyles } from "@material-ui/core";

export const useStylesNestedListItem = makeStyles((theme) => ({
  nested: {
    paddingLeft: theme.spacing(4),
  },
  listRoot: {
    color: theme.palette.primary.main,
  },
}));
