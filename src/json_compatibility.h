#include <json.h>
#include <inttypes.h>

#ifndef HAVE_JSON_OBJECT_OBJECT_GET_EX
int json_object_object_get_ex(struct json_object* obj,
							  const char *key,
							  struct json_object **value);
#endif

#ifndef HAVE_JSON_OBJECT_GET_STRING_LEN
int json_object_get_string_len(struct json_object *obj);
#endif

#ifndef HAVE_JSON_BOOL
typedef int json_bool;
#endif

#ifndef HAVE_JSON_OBJECT_GET_INT64
int64_t json_object_get_int64(struct json_object *jso);
#endif

#ifndef HAVE_JSON_OBJECT_NEW_INT64
struct json_object* json_object_new_int64(int64_t i);
#endif

#ifndef HAVE_JSON_OBJECT_ITER_KEY
struct json_object_iter
{
	char *key;
	struct json_object *val;
	struct lh_entry *entry;
};
#endif

#ifndef HAVE_JSON_TYPE_TO_NAME
const char* json_type_to_name(int t);
#endif

#ifndef json_object_object_foreachC
#define json_object_object_foreachC(obj,iter)							\
	for(iter.entry = json_object_get_object(obj)->head; (iter.entry ? (iter.key = (char*)iter.entry->k, iter.val = (struct json_object*)iter.entry->v, iter.entry) : 0); iter.entry = iter.entry->next)
#endif
