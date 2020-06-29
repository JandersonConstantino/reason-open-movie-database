let reasonReactBlue = "#48a9dc";

// The {j|...|j} feature is just string interpolation, from
// bucklescript.github.io/docs/en/interop-cheatsheet#string-unicode-interpolation
// This allows us to conveniently write CSS, together with variables, by
// constructing a string
let style = {j|
  body {
    background-color: #fff;
    height: calc(100vh - 100px);
    width: calc(100vw - 100px);
    display: flex;
    flex-direction: column;
    align-items: center;
    margin: 50px;
  }
|j};
