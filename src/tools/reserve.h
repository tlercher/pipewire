/* DBus device reservation API */
/* SPDX-FileCopyrightText: Copyright © 2019 Wim Taymans */
/* SPDX-License-Identifier: MIT */

#ifndef DEVICE_RESERVE_H
#define DEVICE_RESERVE_H

#include <dbus/dbus.h>
#include <inttypes.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct rd_device;

struct rd_device_callbacks {
	/** the device is acquired by us */
	void (*acquired) (void *data, struct rd_device *d);
	/** request a release of the device */
	void (*release) (void *data, struct rd_device *d, int forced);
	/** the device is busy by someone else */
	void (*busy) (void *data, struct rd_device *d, const char *name, int32_t priority);
	/** the device is made available by someone else */
	void (*available) (void *data, struct rd_device *d, const char *name);
};

/* create a new device and start watching */
struct rd_device *
rd_device_new(DBusConnection *connection,		/**< Bus to watch */
		const char *device_name,		/**< The device to lock, e.g. "Audio0" */
		const char *application_name,		/**< A human readable name of the application,
							  *  e.g. "PipeWire Server" */
		int32_t priority,			/**< The priority for this application.
							  *  If unsure use 0 */
		const struct rd_device_callbacks *callbacks,	/**< Called when device name is acquired/released */
		void *data);

/** try to acquire the device */
int rd_device_acquire(struct rd_device *d);

/** request the owner to release the device */
int rd_device_request_release(struct rd_device *d);

/** complete the release of the device */
int rd_device_complete_release(struct rd_device *d, int res);

/** release a device */
void rd_device_release(struct rd_device *d);

/** destroy a device */
void rd_device_destroy(struct rd_device *d);

/** check if device name is a valid name */
bool rd_device_valid_device_name(const char *name);

/* Set the application device name for an rd_device object. Returns 0
 * on success, a negative errno style return value on error. */
int rd_device_set_application_device_name(struct rd_device *d, const char *name);

#ifdef __cplusplus
}
#endif

#endif
