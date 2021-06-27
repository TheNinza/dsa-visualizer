import { Tab, Tabs } from "@material-ui/core";
import { Suspense, useEffect, useState } from "react";
import {
  Link,
  useLocation,
  useParams,
  useRouteMatch,
  Switch,
  Route,
} from "react-router-dom";
import Loader from "../../components/loader/loader";
import { useStylesIndividualExperiment } from "./individual-experiment.styles";

const IndividualExperiment = () => {
  // router
  const { id } = useParams();
  const location = useLocation();
  console.log(location);
  const match = useRouteMatch();
  console.log(match);

  // styles
  const classes = useStylesIndividualExperiment();

  // local states
  const [windowSize, setWindowSize] = useState();
  const displayWindowSize = () => {
    // Get width and height of the window excluding scrollbars
    var w = document.documentElement.clientWidth;
    // Display result inside a div element
    setWindowSize(w);
  };

  useEffect(() => {
    displayWindowSize();
    window.addEventListener("resize", (e) => {
      displayWindowSize();
    });
    return () => {
      window.removeEventListener("resize", (e) => console.log(e));
    };
  }, []);

  // static data
  const tabs = [
    {
      name: "Aim",
      pathname: `${match.url}`,
    },
    {
      name: "Theory",
      pathname: `${match.url}/theory`,
    },
    {
      name: "Code",
      pathname: `${match.url}/code`,
    },
    {
      name: "Visualisation",
      pathname: `${match.url}/visualisation`,
    },
  ];

  return (
    <div className={classes.root}>
      <Tabs
        className={classes.tabs}
        variant={windowSize > 880 ? "fullWidth" : "scrollable"}
        value={location.pathname}
        classes={{
          indicator: classes.tabIndicator,
        }}
        TabIndicatorProps={{ children: <span /> }}
        scrollButtons="on"
        textColor="secondary"
      >
        {tabs.map((tab) => (
          <Tab
            label={tab.name}
            value={tab.pathname}
            key={tab.name}
            component={Link}
            to={tab.pathname}
            classes={{
              wrapper: classes.newWraper,
              selected: classes.selectedTab,
            }}
          />
        ))}
      </Tabs>

      <div className={classes.container}>
        {/* <Suspense fallback={<Loader />}> */}
        <Switch>
          <Route exact path={tabs[0].pathname}>
            <div>Aim</div>
          </Route>
          <Route exact path={tabs[1].pathname}>
            <div>Theory</div>
          </Route>
          <Route exact path={tabs[2].pathname}>
            <div>Code</div>
          </Route>
          <Route exact path={tabs[3].pathname}>
            <div>Visuals</div>
          </Route>
        </Switch>
        {/* </Suspense> */}
      </div>
    </div>
  );
};

export default IndividualExperiment;
