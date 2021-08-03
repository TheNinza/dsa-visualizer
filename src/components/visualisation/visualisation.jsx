import { useStylesVisualisation } from "./visualisation.styles";
import visualisationMap from "./visualisation.json";

const Visualisation = ({ param }) => {
  // styles
  const classes = useStylesVisualisation();
  console.log(param);
  return (
    <div className={classes.root}>
      <iframe
        title={param}
        className={classes.iframe}
        src={visualisationMap[param]}
      />
    </div>
  );
};

export default Visualisation;
