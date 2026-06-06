#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__msg__Novel() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__msg__Novel__init(msg: *mut Novel) -> bool;
    fn c_test__msg__Novel__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Novel>, size: usize) -> bool;
    fn c_test__msg__Novel__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Novel>);
    fn c_test__msg__Novel__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Novel>, out_seq: *mut rosidl_runtime_rs::Sequence<Novel>) -> bool;
}

// Corresponds to c_test__msg__Novel
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
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
    pub c: rosidl_runtime_rs::String,

}



impl Default for Novel {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__msg__Novel__init(&mut msg as *mut _) {
        panic!("Call to c_test__msg__Novel__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Novel {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__msg__Novel__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__msg__Novel__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__msg__Novel__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Novel {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Novel where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/msg/Novel";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__msg__Novel() }
  }
}


