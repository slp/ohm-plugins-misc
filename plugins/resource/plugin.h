#ifndef __OHM_RESOURCE_PLUGIN_H__
#define __OHM_RESOURCE_PLUGIN_H__

#include <glib.h>
#include <glib-object.h>
#include <gmodule.h>
#include <ohm/ohm-plugin.h>
#include <ohm/ohm-plugin-log.h>
#include <ohm/ohm-plugin-debug.h>

#define EXPORT __attribute__ ((visibility ("default")))
#define HIDE   __attribute__ ((visibility ("hidden")))

#ifdef  G_MODULE_EXPORT
#undef  G_MODULE_EXPORT
#define G_MODULE_EXPORT EXPORT
#endif

/* FactStore prefix */
#define FACTSTORE_PREFIX                "com.nokia.policy"
#define FACTSTORE_RESOURCE              FACTSTORE_PREFIX ".resource"
#define FACTSTORE_ACTIVE_POLICY_GROUP   FACTSTORE_PREFIX ".active_policy_group"
#define FACTSTORE_ENFORCEMENT_POINT     FACTSTORE_PREFIX ".enforcement_point"

/* these should match the corresponding values in resource-types.h */
#define MEDIA_FLAG_AUDIO_PLAYBACK   0x1
#define MEDIA_FLAG_VIDEO_PLAYBACK   0x2
#define MEDIA_FLAG_AUDIO_RECORDING  0x4
#define MEDIA_FLAG_VIDEO_RECORDING  0x8

extern int DBG_MGR, DBG_CLIENT, DBG_DBUS, DBG_INTERNAL;
extern int DBG_DRES, DBG_FS, DBG_QUE, DBG_MEDIA;


static void plugin_init(OhmPlugin *);
static void plugin_destroy(OhmPlugin *);

/* (sp_)timestamping macros */
#define TIMESTAMP_ADD(step) do {                \
        if (timestamp_add)                      \
            timestamp_add(step);                \
    } while (0)

#endif /* __OHM_RESOURCE_PLUGIN_H__ */

/* 
 * Local Variables:
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 * vim:set expandtab shiftwidth=4:
 */