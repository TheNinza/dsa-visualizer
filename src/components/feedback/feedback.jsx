import { Button, TextField } from "@material-ui/core";
import { useStylesFeedback } from "./feedback.styles";

const Feedback = () => {
  // styles
  const classes = useStylesFeedback();

  return (
    <div className={classes.root}>
      <TextField
        className={classes.feedbackInput}
        multiline
        rows={20}
        variant="outlined"
        label="Your Feedback"
      />

      <Button
        className={classes.submitButton}
        variant="contained"
        color="primary"
      >
        Submit
      </Button>
    </div>
  );
};

export default Feedback;
