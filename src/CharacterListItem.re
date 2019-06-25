[@react.component]
let make = (~character) => {
 let handleClick = (name) => Js.log(name);
  let name = {
    character##name |> React.string;
  };
  let culture =
    switch (character##culture) {
    | Some(culture) => <p> {React.string(culture)} </p>
    | None => React.null
    };
  let playedBy =
    switch (character##playedBy) {
    | Some(playedBy) =>
      <div> {"Played by " ++ playedBy |> React.string} </div>
    | None => React.null
    };
  let aliveOrDead =
    switch (character##isAlive) {
    | true => <div> {"Alive" |> React.string} </div>
    | false => <div> {"Dead" |> React.string} </div>
    };
  <li>
    <strong> <a href="#" onClick={_e => handleClick(character##id)}> name </a> </strong>
    {culture}
    {playedBy}
    {switch (character##allegiances) {
     | Some(allegiances) =>{
       React.array(
         Belt.Array.map(allegiances, a =>
           <div> {"Loyal to " ++ a##name |> React.string} </div>
         ),
       )}
     | None => React.null
     }}
     {aliveOrDead}
  </li>;
  // <a href="#" onClick={_e => select}>
  //   {character##name}
  // </a>
};