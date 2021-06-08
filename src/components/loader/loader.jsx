import { CircularProgress } from "@material-ui/core";

const Loader = ({ homepage = false }) => {
  return (
    <div
      style={{
        display: "flex",
        justifyContent: "center",
        alignItems: "center",
        width: "100%",
        height: homepage ? "100vh" : "100%",
      }}
    >
      <CircularProgress />
    </div>
  );
};

export default Loader;
