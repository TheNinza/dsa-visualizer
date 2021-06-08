import { Box, Typography } from "@material-ui/core";

const HomePageIntroduction = () => {
  return (
    <Box
      display="flex"
      flexDirection="column"
      justifyContent="center"
      alignItems="center"
      component="div"
    >
      <Typography gutterBottom color="primary" variant="h3">
        Introduction
      </Typography>
      <Typography align="center" paragraph variant="h6">
        Welcome to the Data Structures Lab - developed at IIIT Gwalior. Data
        Structures (also called Data Structures and Algorithms in some places)
        is a core course in all computer science undergraduate curricula. The
        course is the basis for understanding several data structures and also
        algorithms that operate on them. The course forms the foundation for
        almost all computer science subjects: compilers, operating systems,
        databases, AI and software engineering. The course comes with a lab in
        most universities in India. The associated lab in university curricula
        focuses on implementation of algorithms operating on the data
        structures, i.e., coding programs on the data structures and algorithms.
        Students embarking on the task of writing programs, however, often have
        difficulty visualizing how operations and algorithms modify a data
        structure. As a result students are often unable to understand or show
        the execution of an algorithm on a given data structure and write code
        effectively. Furthermore, students are unable to visually reason about
        the time and space complexities associated with an algorithm running on
        a data structure. The interactive experiments in this lab will give the
        students an opportunity for learning and better understanding of using
        algorithms.
      </Typography>
    </Box>
  );
};

export default HomePageIntroduction;
