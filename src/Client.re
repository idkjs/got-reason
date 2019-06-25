let serverUri = "http://localhost:4000";
let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.createHttpLink(~uri=serverUri, ()),
    ~cache=ApolloInMemoryCache.createInMemoryCache(),
    (),
  );