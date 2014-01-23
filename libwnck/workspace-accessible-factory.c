/* vim: set sw=2 et: */
/*
 * Copyright 2002 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include "workspace-accessible-factory.h"
#include "workspace-accessible.h"

G_DEFINE_TYPE (WnckWorkspaceAccessibleFactory,
               wnck_workspace_accessible_factory, ATK_TYPE_OBJECT_FACTORY);

static AtkObject* wnck_workspace_accessible_factory_create_accessible (GObject *obj);

static GType wnck_workspace_accessible_factory_get_accessible_type (void);

static void
wnck_workspace_accessible_factory_class_init (WnckWorkspaceAccessibleFactoryClass *klass)
{
  AtkObjectFactoryClass *class = ATK_OBJECT_FACTORY_CLASS (klass);

  class->create_accessible = wnck_workspace_accessible_factory_create_accessible;
  class->get_accessible_type = wnck_workspace_accessible_factory_get_accessible_type;
}

static void
wnck_workspace_accessible_factory_init (WnckWorkspaceAccessibleFactory *factory)
{
}

AtkObjectFactory*
wnck_workspace_accessible_factory_new (void)
{
  GObject *factory;
  factory = g_object_new (WNCK_TYPE_WORKSPACE_ACCESSIBLE_FACTORY, NULL);
  return ATK_OBJECT_FACTORY (factory);
}

static AtkObject*
wnck_workspace_accessible_factory_create_accessible (GObject *obj)
{
  return wnck_workspace_accessible_new (obj);
}

static GType
wnck_workspace_accessible_factory_get_accessible_type (void)
{
  return WNCK_WORKSPACE_TYPE_ACCESSIBLE;
}
