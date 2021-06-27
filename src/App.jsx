import { Suspense, lazy } from "react";
import Loader from "./components/loader/loader";
import Navbar from "./components/navbar/navbar";
import { Switch, Route } from "react-router-dom";

// lazy imports
const Homepage = lazy(() => import("./pages/homepage/homepage"));
const Objective = lazy(() => import("./pages/objective/objective"));
const ExperimentList = lazy(() =>
  import("./pages/experiment-list/experiment-list.jsx")
);
const IndividualExperiment = lazy(() =>
  import("./pages/individual-experiment/individual-experiment.jsx")
);

function App() {
  return (
    <>
      <Navbar />
      <main>
        <Suspense fallback={<Loader />}>
          <Switch>
            <Route exact path="/" component={Homepage} />
            <Route exact path="/introduction" component={Homepage} />
            <Route exact path="/objective" component={Objective} />
            <Route
              exact
              path="/list_of_experiments"
              component={ExperimentList}
            />
            <Route exact path="/experiments" component={ExperimentList} />
            <Route path="/experiments/:id" component={IndividualExperiment} />
          </Switch>
        </Suspense>
      </main>
    </>
  );
}

export default App;
