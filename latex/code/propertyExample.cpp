{
  context myContext;

  std::vector<buffer<int, 1>> bufferList {
    buffer<int, 1>{},
    buffer<int, 1>{property::use_host_ptr{}},
    buffer<int, 1>{property::context_bound{myContext}}
  };

  for(auto& buf : bufferList) {
    if (buf.has_property<property::context_bound>()) {
      auto prop = buf.get_property<property::context_bound>();
      assert(myContext == prop.get_context());
    }
  }
}
