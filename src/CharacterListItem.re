Utils.requireCSS("./CharacterList.css");

[@react.component]
let make = (~character, ~onChangeCharacter) => {
  let handleClick = id => {
    onChangeCharacter(id);
  };
  let name = {
    character##name |> React.string;
  };
  let culture =
    switch (character##culture) {
    | Some(culture) => "(" ++ culture ++ ")" |> React.string
    | None => React.null
    };
  let playedBy =
    switch (character##playedBy) {
    | Some(playedBy) =>
      <div> {"Played by " ++ playedBy |> React.string} </div>
    | None => React.null
    };
  let aliveOrDead =
    character##isAlive
      ? <div> {"Alive" |> React.string} </div>
      : <div> {"Dead" |> React.string} </div>;
  <li>
    <strong>
      <a href="#" onClick={_e => handleClick(character##id)}> name </a>
      culture
    </strong>
    playedBy
    {switch (character##allegiances) {
     | Some(allegiances) =>
       React.array(
         Belt.Array.map(allegiances, a =>
           <div> {"Loyal to " ++ a##name |> React.string} </div>
         ),
       )
     | None => React.null
     }}
    aliveOrDead
  </li>;
};