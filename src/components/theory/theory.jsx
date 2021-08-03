import axios from "axios";
import { useState } from "react";
import { useEffect } from "react";
import ReactMarkdown from "react-markdown";
import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
/* Use `…/dist/cjs/…` if you’re not in ESM! */
import { a11yDark } from "react-syntax-highlighter/dist/esm/styles/prism";
import Loader from "../loader/loader";
import { useStylesTheory } from "./theory.styles";

/**
 * Passing support for syntax hightlighting in markdown
 */

const components = {
  code({ node, inline, className, children, ...props }) {
    const match = /language-(\w+)/.exec(className || "");
    return !inline && match ? (
      <SyntaxHighlighter
        style={a11yDark}
        language={match[1]}
        PreTag="div"
        children={String(children).replace(/\n$/, "")}
        {...props}
      />
    ) : (
      <code className={className} {...props}>
        {children}
      </code>
    );
  },
};

const Theory = ({ param }) => {
  // styles
  const classes = useStylesTheory();

  // local states
  const [markdownText, setMarkdownText] = useState("");
  const [loading, setLoading] = useState(true);

  // hooks

  useEffect(() => {
    fectchMarkdown(param);
  }, [param]);

  // custom functions
  const fectchMarkdown = async (id) => {
    setLoading(true);
    try {
      const { data } = await axios.get(`/theory/${id}.md`);
      setMarkdownText(data);
      setLoading(false);
    } catch (error) {
      setLoading(false);
      alert("Error fetching theory");
    }
  };

  return (
    <div className={classes.root}>
      {markdownText === "" || loading ? (
        <Loader />
      ) : (
        <ReactMarkdown
          className={classes.markdownContainer}
          components={components}
          children={markdownText}
        />
      )}
    </div>
  );
};

export default Theory;
