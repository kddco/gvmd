/* OpenVAS Manager
 * $Id$
 * Description: Manager Manage library: SQL backend headers.
 *
 * Authors:
 * Matthew Mundell <matthew.mundell@intevation.de>
 *
 * Copyright:
 * Copyright (C) 2010 Greenbone Networks GmbH
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2,
 * or, at your option, any later version as published by the Free
 * Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef OPENVAS_MANAGER_MANAGE_SQL_H
#define OPENVAS_MANAGER_MANAGE_SQL_H

#include "manage.h"

int set_report_slave_progress (report_t, int);

void set_report_slave_task_uuid (report_t, const char *);

int set_task_requested (task_t, task_status_t *);

void init_task_file_iterator (iterator_t *, task_t, const char *);
const char *task_file_iterator_name (iterator_t *);
const char *task_file_iterator_content (iterator_t *);

void set_task_schedule_next_time (task_t, time_t);

void init_otp_pref_iterator (iterator_t *, config_t, const char *);
const char *otp_pref_iterator_name (iterator_t *);
const char *otp_pref_iterator_value (iterator_t *);

lsc_credential_t target_lsc_credential (target_t);
const char *lsc_credential_iterator_password (iterator_t *);

int create_report (task_t, char **, task_status_t);

char *escalator_data (escalator_t, const char *, const char *);

time_t add_months (time_t, int);

time_t months_between (time_t, time_t);

void init_task_schedule_iterator (iterator_t *);

void cleanup_task_schedule_iterator (iterator_t *);

task_t task_schedule_iterator_task (iterator_t *);

const char *task_schedule_iterator_task_uuid (iterator_t *);

schedule_t task_schedule_iterator_schedule (iterator_t *);

time_t task_schedule_iterator_next_time (iterator_t *);

time_t task_schedule_iterator_period (iterator_t *);

time_t task_schedule_iterator_period_months (iterator_t *);

time_t task_schedule_iterator_duration (iterator_t *);

gboolean task_schedule_iterator_start_due (iterator_t *);

gboolean task_schedule_iterator_stop_due (iterator_t *);

time_t task_schedule_iterator_first_time (iterator_t *);

const char *task_schedule_iterator_owner_uuid (iterator_t *);

const char *task_schedule_iterator_owner_name (iterator_t *);

void reinit_manage_process ();

void manage_update_nvti_cache ();

#endif /* not OPENVAS_MANAGER_MANAGE_SQL_H */
