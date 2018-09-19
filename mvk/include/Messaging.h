#pragma once

/*
 * DevNote:
 * Set of macro to create all supported MVK messages
 */


// -----------------------------------------------------------------------------
// MVK Messaging format (Megamodel mode)
// -----------------------------------------------------------------------------

#define MSG_USER_CONNECT(uuid_) \
    "op=set_input&value=\"" + uuid_ + "\"&taskname=task_manager"

#define MSG_USER_LOGIN(value_, uuid_) \
    "value=\"" + value_ + "\"" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_USER_QUIET(uuid_) \
    "value=\"quiet\"&op=set_input&taskname=" + uuid_


// -----------------------------------------------------------------------------
// MVK Messaging format (Megamodel mode)
// -----------------------------------------------------------------------------

#define MSG_MODEL_LIST(path_, uuid_) \
    "data=[\"model_list\",\"" + path_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_MODEL_ADD(name_, mmodel_, syntax_, uuid_) \
    "data=[\"model_add\",\"" + mmodel_ + "\",\"" + name_ + \
    "\",\"" + syntax_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_MODEL_DEL(name_, uuid_) \
    "data=[\"model_delete\",\"" + name_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_MODEL_VERIFY(model_, mmodel_, uuid_) \
    "data=[\"verify\",\"" + model_ + "\",\"" + mmodel_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_MODEL_MODIFY(model_, mmodel_, uuid_) \
    "data=[\"model_modify\",\"" + model_ + "\",\"" + mmodel_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_MODEL_EXIT(uuid_) \
    "value=\"exit\"&op=set_input&taskname=" + uuid_


// -----------------------------------------------------------------------------
// MVK Messaging format (Model mode)
// -----------------------------------------------------------------------------

#define MSG_ELT_LIST(uuid_) \
    "value=\"list_full\"&op=set_input&taskname=" + uuid_

#define MSG_ELT_LIST_JSON(uuid_) \
    "value=\"JSON\"&op=set_input&taskname=" + uuid_

#define MSG_ELT_CREA(type_, name_, uuid_) \
    "data=[\"instantiate_node\",\"" + type_ + "\",\"" + name_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_ELT_DEL(name_, uuid_) \
    "data=[\"delete\",\"" + name_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_EDGE_CREA(type_, name_, from_, to_, uuid_) \
    "data=[\"instantiate_edge\",\"" + type_ + "\",\"" + name_ \
    + "\",\"" + from_ + "\",\"" + to_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_ATTR_SET(elt_, attrType_, attrValue_, uuid_) \
    "data=[\"attr_add\",\"" + elt_ + "\",\"" + attrType_ \
    + "\",\"" + attrValue_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_ATTR_DEL(elt_, attrType_, uuid_) \
    "data=[\"attr_delete\",\"" + elt_ + "\",\"" + attrType_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_ATTR_DEFINE(elt_, type_, name_, uuid_) \
    "data=[\"define_attribute\",\"" + elt_ + "\",\"" \
    + name_ + "\",\"" + type_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_

#define MSG_ATTR_SET_CODE(elt_, type_, value_, uuid_) \
    "data=[\"attr_add_code\",\"" + elt_ + "\",\"" + type_ \
    + "\",\"" + value_ + "\"]" + \
    "&op=set_input&taskname=" + uuid_


