import { CircularProgress } from "@material-ui/core";
import { lazy, Suspense } from "react";
import { Route, Switch } from "react-router";
import "./App.css";
import Footer from "./components/footer/footer";
import Loader from "./components/loader/loader";

// lazy loading pages
const Homepage = lazy(() => import("./pages/homepage/homepage"));

function App() {
  return (
    <div className="App">
      <Suspense fallback={<Loader homepage={true} />}>
        <Switch>
          <Route path="/" component={Homepage} />
        </Switch>

        <Footer />
      </Suspense>
    </div>
  );
}

export default App;
