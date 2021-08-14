import { useStylesHomepage } from "./homepage.styles";
import Timeline from "@material-ui/lab/Timeline";
import TimelineItem from "@material-ui/lab/TimelineItem";
import TimelineSeparator from "@material-ui/lab/TimelineSeparator";
import TimelineConnector from "@material-ui/lab/TimelineConnector";
import TimelineContent from "@material-ui/lab/TimelineContent";
import TimelineDot from "@material-ui/lab/TimelineDot";
import LaptopMacIcon from "@material-ui/icons/LaptopMac";
import RepeatIcon from "@material-ui/icons/Repeat";
import Paper from "@material-ui/core/Paper";
import Typography from "@material-ui/core/Typography";
import { List, ListItem } from "@material-ui/core";
import BuildIcon from "@material-ui/icons/Build";
import ListIcon from "@material-ui/icons/List";

const Homepage = () => {
  const classes = useStylesHomepage();

  return (
    <div className={classes.root}>
      <Timeline style={{ width: "100%" }} align="alternate">
        <TimelineItem>
          <TimelineSeparator>
            <TimelineDot color="primary">
              <BuildIcon />
            </TimelineDot>
            <TimelineConnector />
          </TimelineSeparator>
          <TimelineContent>
            <Paper elevation={3} className={classes.paper}>
              <Typography
                color="primary"
                gutterBottom
                variant="h6"
                component="h1"
              >
                What is a Virtual Lab?
              </Typography>
              <Typography>
                In the most general sense, virtual lab aims to provide the
                facilities online that is provided by a physical lab, i.e., it
                provides a simulated learning environment that allow to complete
                laboratory experiments online. It helps in understanding the
                concepts and experiments without the use of scarce costly
                equipments. Another view of the virtual laboratory is as a tool
                for distance learning and/or experimentation that allows to
                share knowledge, data, voice, video, tools, etc.
              </Typography>
            </Paper>
          </TimelineContent>
        </TimelineItem>
        <TimelineItem>
          <TimelineSeparator>
            <TimelineDot color="secondary">
              <LaptopMacIcon />
            </TimelineDot>
            <TimelineConnector />
          </TimelineSeparator>
          <TimelineContent>
            <Paper elevation={3} className={classes.paper}>
              <Typography
                color="secondary"
                gutterBottom
                variant="h6"
                component="h1"
              >
                Virtual Lab for Data Structures and Algorithms
              </Typography>
              <Typography>
                Here, the second view of the virtual lab is adopted for the Data
                Structures and Algorithms as it fits best for this course to
                share the knowledge using theory, algorithm, and demonstration.
                The students may understand and experiment with the codes
                locally at their computing device.
              </Typography>
            </Paper>
          </TimelineContent>
        </TimelineItem>
        <TimelineItem>
          <TimelineSeparator>
            <TimelineDot color="primary">
              <ListIcon />
            </TimelineDot>
            <TimelineConnector className={classes.secondaryTail} />
          </TimelineSeparator>
          <TimelineContent>
            <Paper elevation={3} className={classes.paper}>
              <Typography
                color="primary"
                gutterBottom
                variant="h6"
                component="h1"
              >
                Salient Features
              </Typography>
              <List style={{ fontSize: "1rem" }}>
                <ListItem>Anywhere anytime laboratory</ListItem>
                <ListItem>Free to use</ListItem>
                <ListItem>
                  Accessibility through PC/laptop/tablet/smartphone
                </ListItem>
                <ListItem>Facilitates Learning at self-pace</ListItem>
              </List>
            </Paper>
          </TimelineContent>
        </TimelineItem>
        <TimelineItem>
          <TimelineSeparator>
            <TimelineDot color="secondary">
              <RepeatIcon />
            </TimelineDot>
          </TimelineSeparator>
          <TimelineContent>
            <Paper elevation={3} className={classes.paper}>
              <Typography
                color="secondary"
                gutterBottom
                variant="h6"
                component="h1"
              >
                Explore
              </Typography>
              <Typography>Go to List Of Experiments for more</Typography>
            </Paper>
          </TimelineContent>
        </TimelineItem>
      </Timeline>
    </div>
  );
};

export default Homepage;
