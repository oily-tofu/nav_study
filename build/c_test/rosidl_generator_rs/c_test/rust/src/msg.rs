#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to c_test__msg__Novel

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Novel {

    // This member is not documented.
    #[allow(missing_docs)]
    pub a: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub b: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub c: std::string::String,

}



impl Default for Novel {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Novel::default())
  }
}

impl rosidl_runtime_rs::Message for Novel {
  type RmwMsg = super::msg::rmw::Novel;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        a: msg.a,
        b: msg.b,
        c: msg.c.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      a: msg.a,
      b: msg.b,
        c: msg.c.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      a: msg.a,
      b: msg.b,
      c: msg.c.to_string(),
    }
  }
}


