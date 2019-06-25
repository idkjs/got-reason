Utils.requireCSS("./CharacterDetail.css");

[@react.component]
let make = (~character, ~onChangeCharacter) => {
      Js.log2("CHARACTER: ", character);

  let handleClick = id => {
    Js.log2("HANDLE_CLICK_ID", id);
    onChangeCharacter(id);
  };
  // let test = (character) =>
  //   switch (character##father) {
  //   | Some(father) =>
  //   // Js.log2("FATHER_TEST: ", father);
  //     let name =
  //       switch (father##name) {
  //       | Some(name) => name |> Js.log
  //       | None => "React.null"->Js.log
  //       };
  //       name;
  //     let id =
  //       switch (father##id) {
  //       | Some(id) => id |> Js.log
  //       | None =>"React.null"->Js.log
  //       };
  //       id;
  //   | None => "NO_FATHER_ID"->Js.log
  //   };
    //  let getId = (c) =>
    //     switch (c##id) {
    //     | Some(id) => id |> React.string
    //     | None => React.null
    //     };
  let father = (~label: string,character) =>
    switch (character##father) {
    | Some(father) =>
      let name =
        switch (father##name) {
        | Some(name) => name |> React.string
        | None => React.null
        };
        // let id = getId(father);
      // let id =
      //   switch (father##id) {
      //   | Some(id) => id |> ignore
      //   | None => ()
      //   };
      <div>
        <strong> label->React.string </strong>
        // {""}
        <a href="#" onClick={_e => handleClick(father##id)}>
          {name}
        </a>
      </div>;
    | None => React.null
    };

  // let mother = (~label: string,character) =>
  //   switch (character##mother) {
  //   | Some(mother) =>
  //     let name =
  //       switch (mother##name) {
  //       | Some(name) => name |> React.string
  //       | None => React.null
  //       };
  //       let id = getId(mother);
  //     // let id =
  //     //   switch (mother##id) {
  //     //   | Some(id) => id |> React.string
  //     //   | None => React.null
  //     //   };
  //     <div>
  //       <strong> label->React.string </strong>
  //       // {""}
  //       <a href="#" onClick={_e => handleClick(id)}>
  //         name
  //       </a>
  //     </div>;
  //   | None => React.null
  //   };

  // Js.log2("FATHER_TEST: ", test(character));
  // Js.log2("FATHER_TEST: ", test(character));

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
    {father("Father: ", character)}
    // {mother("Mother: ",character)}
    // {
    //   renderCharacter("Father: ", character);
    // }
    // {
    //   renderCharacter("Mother: ", character);
    // }
    // {
    //   renderCharacter("Spouse: ", character);
    // }
  </>;
};