// Entry point

[@bs.val] external document: Js.t({..}) = "document";

let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= ExampleStyles.style;

ReactDOMRe.render(
  <Home />,
  document##getElementById("root")
);
