/* 
 * Copyright (c) 2012, 2014, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#pragma once

namespace MySQL {
  namespace Forms {
    
    ref class TreeViewNode;

    public class TreeNodeViewWrapper : public ViewWrapper
    {
    protected:
      TreeNodeViewWrapper(mforms::TreeNodeView *backend);
      virtual ~TreeNodeViewWrapper();

      static bool create(mforms::TreeNodeView *backend, mforms::TreeOptions options);
      static int add_column(mforms::TreeNodeView *backend, mforms::TreeColumnType type,
        const std::string &name, int initial_width, bool editable);
      static void end_columns(mforms::TreeNodeView *backend);
      
      static void clear(mforms::TreeNodeView *backend);

      static mforms::TreeSelectionMode get_selection_mode(mforms::TreeNodeView *backend);
      static void set_selection_mode(mforms::TreeNodeView *backend, mforms::TreeSelectionMode mode);
      static std::list<mforms::TreeNodeRef> get_selection(mforms::TreeNodeView *backend);
      static mforms::TreeNodeRef get_selected_node(mforms::TreeNodeView *backend);
      static void clear_selection(mforms::TreeNodeView *backend);
      static void set_selected(mforms::TreeNodeView *backend, mforms::TreeNodeRef node, bool flag);

      static void set_allow_sorting(mforms::TreeNodeView *backend, bool flag);
      static void set_row_height(mforms::TreeNodeView *backend, int h);

      static void freeze_refresh(mforms::TreeNodeView *backend, bool flag);

      static mforms::TreeNodeRef root_node(mforms::TreeNodeView *backend);

      static mforms::TreeNodeRef node_at_row(mforms::TreeNodeView *backend, int row);
      static mforms::TreeNodeRef node_at_position(mforms::TreeNodeView *backend, base::Point position);
      static int row_for_node(mforms::TreeNodeView *backend, mforms::TreeNodeRef node);
      static mforms::TreeNodeRef node_with_tag(mforms::TreeNodeView *backend, const std::string &tag);

      static void set_column_title(mforms::TreeNodeView *backend, int column, const std::string &title);

      static void set_column_visible(mforms::TreeNodeView *backend, int column, bool flag);
      static bool get_column_visible(mforms::TreeNodeView *backend, int column);

      static void set_column_width(mforms::TreeNodeView *backend, int column, int width);
      static int get_column_width(mforms::TreeNodeView *backend, int column);

      virtual mforms::DropPosition get_drop_position();
    public:
      void set_row_height(int h);

      mforms::TreeSelectionMode get_selection_mode();
      void set_selection_mode(mforms::TreeSelectionMode mode);

      void clear_selection();
      std::list<mforms::TreeNodeRef> get_selection();
      void set_selected(mforms::TreeNodeRef node, bool flag);

      void allow_column_sorting(bool flag);

      void freeze_refresh(bool flag);

      mforms::TreeNodeRef root_node();
      
      mforms::TreeNodeRef node_at_row(int row);
      mforms::TreeNodeRef node_at_position(base::Point position);
      int row_for_node(mforms::TreeNodeRef node);

      void set_column_title(int column, const std::string &title);

      void set_column_visible(int column, bool flag);
      bool is_column_visible(int column);

      void set_column_width(int column, int width);
      int get_column_width(int column);

      // Internal functions.
      void process_mapping(TreeViewNode ^node, const std::string &tag);
      void node_value_set(int column);

      static void init();
    };
  }
}

