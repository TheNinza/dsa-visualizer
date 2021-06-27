import { useStylesExperimentList } from "./experiment-list.styles";
import experiments from "./experiment-list.json";
import { Typography, List } from "@material-ui/core";
import NestedListItem from "../../components/nested-listitem/nested-listitem";

const ExperimentList = () => {
  // styles
  const classes = useStylesExperimentList();

  return (
    <div className={classes.root}>
      <Typography align="center" gutterBottom color="primary" variant="h3">
        List Of Experiments
      </Typography>

      {/* <Typography color="secondary" variant="h5">
        Ace your DSA skills in following topics:
      </Typography> */}

      <List className={classes.listRoot}>
        {experiments.map(({ name, subSection }) => (
          <NestedListItem name={name} subsection={subSection} />
        ))}
      </List>
    </div>
  );
};

export default ExperimentList;
