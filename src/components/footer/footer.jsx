import { useStylesFooter } from "./footer.styles";

const Footer = () => {
  // styles
  const classes = useStylesFooter();

  return <div className={classes.footer}>This is the footer section</div>;
};

export default Footer;
