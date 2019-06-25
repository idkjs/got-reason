Utils.requireCSS("./CharacterDetail.css");

[@react.component]
let make = (~character, ~onChangeCharacter) => {
      Js.log2("CHARACTER: ", character);

  let handleClick = id => {
    // Js.log2("HANDLE_CLICK_ID", id);
    onChangeCharacter(id);
  };
  // let test = (character) =>
  //   switch (character##father) {
  //   | Some(father) =>
  //     let name =
  //       switch (father##name) {
  //       | Some(name) => name |> Js.log
  //       | None => "React.null"->Js.log
  //       };
  //     let id =
  //       switch (father##id) {
  //       | Some(id) => id |> Js.log
  //       | None =>"React.null"->Js.log
  //       };
  //   | None => "NO_FATHER"->Js.log
  //   };
  // let father = (character) =>
  //   switch (character##father) {
  //   | Some(father) =>
  //     let name =
  //       switch (father##name) {
  //       | Some(name) => name |> React.string
  //       | None => React.null
  //       };
  //     let id =
  //       switch (father##id) {
  //       | Some(id) => id |> React.string
  //       | None => React.null
  //       };
  //     <div>
  //       <strong> "Father: "->React.string </strong>
  //       // {""}
  //       <a href="#" onClick={_e => onChangeCharacter(id)}>
  //         name
  //       </a>
  //     </div>;
  //   | None => React.null
  //   };

  // Js.log2("FATHER_TEST: ", test);

  let renderItem = (~label: string, ~item) => {
    switch (item) {
    | Some(item) =>
      <div> <strong> label->React.string </strong> item->React.string </div>
    | None => React.null
    };
  };

  let renderListItem = (~label: string, ~items: option('a)) => {
    switch (items) {
    | Some(items) =>
      <div> <strong> label->React.string </strong> </div>;
      React.array(
        Belt.Array.map(items, i =>
          <div> {"Loyal to " ++ i |> React.string} </div>
        ),
      );
    | None => React.null
    };
  };

  let renderCharacter = (~label: string, ~c) => {
    switch (c##name) {
    | Some(name) =>
      <div>
         <strong> label->React.string </strong> name->React.string </div>
        // {""}
        // <a href="#" onClick={_e => handleClick(c##id)}> {name->React.string} </a>
    | None => React.null
    };
  };
  <>
    <h2> {character##name |> React.string} </h2>
    {switch (character##allegiances) {
     | Some(allegiances) =>
       React.array(
         Belt.Array.map(allegiances, a =>
           <div> {"Loyal to " ++ a##name |> React.string} </div>
         ),
       )
     | None => React.null
     }}
    {renderItem("Culture", character##culture)}
    {renderItem("Played by", character##playedBy)}
    //    {switch (character##aliases) {
    //  | Some(aliases) =>
    //    React.array(
    //      Belt.Array.map(aliases, a =>
    //        <div> {"Loyal to " ++ a |> React.string} </div>
    //      ),
    //    )
    //  | None => React.null
    //  }}
    {renderListItem("Aliases: ", character##aliases)}
    {renderListItem("Titles: ", character##titles)}
    {renderItem("Born: ", character##born)}
    {renderItem("Died: ", character##died)}
    {renderItem("Culture: ", character##culture)}
    // {father(character)}
    // {
    //   renderCharacter("Father", character##father);
    // }
    // {
    //   renderCharacter("Mother", character##mother);
    // }
    // {
    //   renderCharacter("Spouse", character##spouse);
    // }
  </>;
};