open Home_Styles;

type movie = {
  poster: string,
  title: string,
  year: string,
  imdbID: string,
};

module Decode = {
  let movie = movie =>
    Json.Decode.{
      poster: movie |> field("Poster", string),
      title: movie |> field("Title", string),
      year: movie |> field("Year", string),
      imdbID: movie |> field("imdbID", string),
    };

  let movies = json => Json.Decode.list(movie, json);
};

[@react.component]
let make = () => {
  let (text, setText) = React.useState(_ => "");
  let (items, setItems) = React.useState(_ => []);

  let onChange = event => {
    let updatedText = ReactEvent.Form.target(event)##value;
    setText(_ => updatedText);
  };

  let onSubmit = event => {
    Js.Promise.(
      Axios.get("http://www.omdbapi.com/?apikey=8776ef0d&s=" ++ text)
      |> then_(response => {
           let parsedData = response##data##_Search |> Decode.movies;
           setItems(_ => parsedData);
           resolve();
         })
      |> catch(_ => resolve())
      |> ignore
    );

    ReactEvent.Form.preventDefault(event);
  };
  Js.log(items);
  <div>
    <form onSubmit>
      <div className=Styles.containerInput>
        <input className=Styles.input value=text type_="text" onChange />
      </div>
    </form>
    <div className=Styles.container>
      {items->Belt.List.map(item =>
         <div key={item.imdbID} className=Styles.item>
           {switch (item.poster) {
            | "N/A" => <div className=Styles.image />
            | _ => <img className=Styles.image src={item.poster} alt="image" />
            }}
           <span className=Styles.title>
             {React.string(item.title ++ "(" ++ item.year ++ ")")}
           </span>
         </div>
       )
       |> Belt.List.toArray
       |> ReasonReact.array}
    </div>
  </div>;
};
