/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2006 William Jon McCann <mccann@jhu.edu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */


#ifndef __GDM_XDMCP_MANAGER_H
#define __GDM_XDMCP_MANAGER_H

#include <glib-object.h>

G_BEGIN_DECLS

#define GDM_TYPE_XDMCP_MANAGER         (gdm_xdmcp_manager_get_type ())
#define GDM_XDMCP_MANAGER(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GDM_TYPE_XDMCP_MANAGER, GdmXdmcpManager))
#define GDM_XDMCP_MANAGER_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), GDM_TYPE_XDMCP_MANAGER, GdmXdmcpManagerClass))
#define GDM_IS_XDMCP_MANAGER(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GDM_TYPE_XDMCP_MANAGER))
#define GDM_IS_XDMCP_MANAGER_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), GDM_TYPE_XDMCP_MANAGER))
#define GDM_XDMCP_MANAGER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GDM_TYPE_XDMCP_MANAGER, GdmXdmcpManagerClass))

typedef struct GdmXdmcpManagerPrivate GdmXdmcpManagerPrivate;

typedef struct
{
	GObject		        parent;
	GdmXdmcpManagerPrivate *priv;
} GdmXdmcpManager;

typedef struct
{
	GObjectClass   parent_class;
} GdmXdmcpManagerClass;

typedef enum
{
	 GDM_XDMCP_MANAGER_ERROR_GENERAL
} GdmXdmcpManagerError;

#define GDM_XDMCP_MANAGER_ERROR gdm_xdmcp_manager_error_quark ()

GQuark		    gdm_xdmcp_manager_error_quark	      (void);
GType		    gdm_xdmcp_manager_get_type		      (void);

GdmXdmcpManager *   gdm_xdmcp_manager_new		      (void);

void                gdm_xdmcp_manager_set_port                (GdmXdmcpManager *manager,
							       guint            port);
gboolean            gdm_xdmcp_manager_start                   (GdmXdmcpManager *manager,
							       GError         **error);

G_END_DECLS

#endif /* __GDM_XDMCP_MANAGER_H */
