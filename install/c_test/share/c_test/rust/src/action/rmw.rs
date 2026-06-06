
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_Goal() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__action__Atest_Goal__init(msg: *mut Atest_Goal) -> bool;
    fn c_test__action__Atest_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Atest_Goal>, size: usize) -> bool;
    fn c_test__action__Atest_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Atest_Goal>);
    fn c_test__action__Atest_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Atest_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Atest_Goal>) -> bool;
}

// Corresponds to c_test__action__Atest_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Atest_Goal {
    /// 客户端 → 服务端：发送的目标
    pub order: i32,

}



impl Default for Atest_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__action__Atest_Goal__init(&mut msg as *mut _) {
        panic!("Call to c_test__action__Atest_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Atest_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Atest_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Atest_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/action/Atest_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_Goal() }
  }
}


#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_Result() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__action__Atest_Result__init(msg: *mut Atest_Result) -> bool;
    fn c_test__action__Atest_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Atest_Result>, size: usize) -> bool;
    fn c_test__action__Atest_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Atest_Result>);
    fn c_test__action__Atest_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Atest_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Atest_Result>) -> bool;
}

// Corresponds to c_test__action__Atest_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Atest_Result {
    /// 服务端 → 客户端：最终结果
    pub sequence: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for Atest_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__action__Atest_Result__init(&mut msg as *mut _) {
        panic!("Call to c_test__action__Atest_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Atest_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Atest_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Atest_Result where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/action/Atest_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_Result() }
  }
}


#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__action__Atest_Feedback__init(msg: *mut Atest_Feedback) -> bool;
    fn c_test__action__Atest_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Atest_Feedback>, size: usize) -> bool;
    fn c_test__action__Atest_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Atest_Feedback>);
    fn c_test__action__Atest_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Atest_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Atest_Feedback>) -> bool;
}

// Corresponds to c_test__action__Atest_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Atest_Feedback {
    /// 服务端 → 客户端：中间反馈
    pub partial_sequence: rosidl_runtime_rs::Sequence<i32>,

}



impl Default for Atest_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__action__Atest_Feedback__init(&mut msg as *mut _) {
        panic!("Call to c_test__action__Atest_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Atest_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Atest_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Atest_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/action/Atest_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_Feedback() }
  }
}


#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__action__Atest_FeedbackMessage__init(msg: *mut Atest_FeedbackMessage) -> bool;
    fn c_test__action__Atest_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Atest_FeedbackMessage>, size: usize) -> bool;
    fn c_test__action__Atest_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Atest_FeedbackMessage>);
    fn c_test__action__Atest_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Atest_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Atest_FeedbackMessage>) -> bool;
}

// Corresponds to c_test__action__Atest_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Atest_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Atest_Feedback,

}



impl Default for Atest_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__action__Atest_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to c_test__action__Atest_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Atest_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Atest_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Atest_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/action/Atest_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_FeedbackMessage() }
  }
}




#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__action__Atest_SendGoal_Request__init(msg: *mut Atest_SendGoal_Request) -> bool;
    fn c_test__action__Atest_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Atest_SendGoal_Request>, size: usize) -> bool;
    fn c_test__action__Atest_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Atest_SendGoal_Request>);
    fn c_test__action__Atest_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Atest_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Atest_SendGoal_Request>) -> bool;
}

// Corresponds to c_test__action__Atest_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Atest_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Atest_Goal,

}



impl Default for Atest_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__action__Atest_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to c_test__action__Atest_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Atest_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Atest_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Atest_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/action/Atest_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_SendGoal_Request() }
  }
}


#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__action__Atest_SendGoal_Response__init(msg: *mut Atest_SendGoal_Response) -> bool;
    fn c_test__action__Atest_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Atest_SendGoal_Response>, size: usize) -> bool;
    fn c_test__action__Atest_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Atest_SendGoal_Response>);
    fn c_test__action__Atest_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Atest_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Atest_SendGoal_Response>) -> bool;
}

// Corresponds to c_test__action__Atest_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Atest_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Atest_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__action__Atest_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to c_test__action__Atest_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Atest_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Atest_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Atest_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/action/Atest_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_SendGoal_Response() }
  }
}


#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__action__Atest_GetResult_Request__init(msg: *mut Atest_GetResult_Request) -> bool;
    fn c_test__action__Atest_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Atest_GetResult_Request>, size: usize) -> bool;
    fn c_test__action__Atest_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Atest_GetResult_Request>);
    fn c_test__action__Atest_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Atest_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Atest_GetResult_Request>) -> bool;
}

// Corresponds to c_test__action__Atest_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Atest_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Atest_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__action__Atest_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to c_test__action__Atest_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Atest_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Atest_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Atest_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/action/Atest_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_GetResult_Request() }
  }
}


#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "c_test__rosidl_generator_c")]
extern "C" {
    fn c_test__action__Atest_GetResult_Response__init(msg: *mut Atest_GetResult_Response) -> bool;
    fn c_test__action__Atest_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Atest_GetResult_Response>, size: usize) -> bool;
    fn c_test__action__Atest_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Atest_GetResult_Response>);
    fn c_test__action__Atest_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Atest_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Atest_GetResult_Response>) -> bool;
}

// Corresponds to c_test__action__Atest_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Atest_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Atest_Result,

}



impl Default for Atest_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !c_test__action__Atest_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to c_test__action__Atest_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Atest_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { c_test__action__Atest_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Atest_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Atest_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "c_test/action/Atest_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__c_test__action__Atest_GetResult_Response() }
  }
}






#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__c_test__action__Atest_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to c_test__action__Atest_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Atest_SendGoal;

impl rosidl_runtime_rs::Service for Atest_SendGoal {
    type Request = Atest_SendGoal_Request;
    type Response = Atest_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__c_test__action__Atest_SendGoal() }
    }
}




#[link(name = "c_test__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__c_test__action__Atest_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to c_test__action__Atest_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Atest_GetResult;

impl rosidl_runtime_rs::Service for Atest_GetResult {
    type Request = Atest_GetResult_Request;
    type Response = Atest_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__c_test__action__Atest_GetResult() }
    }
}


