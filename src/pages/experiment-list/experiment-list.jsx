import { useStylesExperimentList } from "./experiment-list.styles";
import experiments from "./experiment-list.json";
import {
  createMuiTheme,
  responsiveFontSizes,
  ThemeProvider,
  Typography,
  List,
  MuiThemeProvider,
} from "@material-ui/core";
import NestedListItem from "../../components/nested-listitem/nested-listitem";

const ExperimentList = () => {
  // styles
  const classes = useStylesExperimentList();
  let theme = createMuiTheme();
  theme = responsiveFontSizes(theme);
  const heading = "List Of Experiments";

  return (
    <div className={classes.root}>
      <MuiThemeProvider theme={theme}>
        <Typography align="center" gutterBottom color="primary" variant="h3">{heading}</Typography>
      </MuiThemeProvider>

      {/* <Typography color="secondary" variant="h5">
        Ace your DSA skills in following topics:
      </Typography> */}

      <List className={classes.listRoot}>
        {experiments.map(({ name, subSection }, idx) => (
          <NestedListItem name={name} subsection={subSection} key={idx} />
        ))}
      </List>
    </div>
  );
};

export default ExperimentList;
