import { FormControlLabel, Paper, Switch, Tab, Tabs } from "@material-ui/core";
import { useState } from "react";
import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
import { useStylesCode } from "./code.styles";
import {
  coy,
  vscDarkPlus,
} from "react-syntax-highlighter/dist/esm/styles/prism";
import { useEffect } from "react";
import axios from "axios";

// static values
const LANGUAGE_ARRAY = ["c", "cpp", "py"];

const Code = ({ param }) => {
  // styles
  const classes = useStylesCode();

  // local state
  const [value, setValue] = useState(1);
  const [isDarkTheme, setIsDarkTheme] = useState(false);
  const [codeDetails, setCodeDetails] = useState({
    codeString: "",
    available: false,
  });

  // hooks
  useEffect(() => {
    fetchCodes(param, value);
  }, [param, value]);

  // custom functions
  const handleChange = (_event, newValue) => {
    setValue(newValue);
  };

  const fetchCodes = async (id, tabIndex) => {
    try {
      const { data } = await axios.get(
        `/codes/${id}/${id}.${LANGUAGE_ARRAY[tabIndex]}`
      );
      setCodeDetails({
        codeString: data,
        available: true,
      });
    } catch (error) {
      console.error(error);
      setCodeDetails({
        codeString: "",
        available: false,
      });
    }
  };
  return (
    <div className={classes.root}>
      <div className={classes.tabThemeContainer}>
        <Tabs
          value={value}
          onChange={handleChange}
          indicatorColor="primary"
          textColor="primary"
          variant="scrollable"
        >
          <Tab label="C" />
          <Tab label="C++" />
          <Tab label="Python" />
        </Tabs>
        <div className={classes.toggleSwitch}>
          <FormControlLabel
            control={
              <Switch
                checked={isDarkTheme}
                onChange={(e) => setIsDarkTheme(e.target.checked)}
                color="primary"
              />
            }
            label="Toggle Dark Theme"
          />
        </div>
      </div>

      <Paper elevation={2} className={classes.codeContainer}>
        {codeDetails.available ? (
          <SyntaxHighlighter
            style={isDarkTheme ? vscDarkPlus : coy}
            language={LANGUAGE_ARRAY[value]}
          >
            {codeDetails.codeString}
          </SyntaxHighlighter>
        ) : (
          <h2 className={classes.notFound}>Not available yet</h2>
        )}
      </Paper>
    </div>
  );
};

export default Code;
