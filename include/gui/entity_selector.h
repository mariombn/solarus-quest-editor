/*
 * Copyright (C) 2014-2015 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus Quest Editor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus Quest Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUSEDITOR_ENTITY_SELECTOR_H
#define SOLARUSEDITOR_ENTITY_SELECTOR_H

#include "entities/entity_traits.h"
#include <QComboBox>

class MapModel;

/**
 * @brief A combo box that allows to choose a map entity from its name.
 */
class EntitySelector : public QComboBox {
  Q_OBJECT

public:

  EntitySelector(QWidget* parent);

  const MapModel* get_map() const;
  void set_map(const MapModel* map);
  bool is_filtered_by_entity_type() const;
  void set_filtered_by_entity_type(bool filtered);
  EntityType get_entity_type_filter() const;
  void set_entity_type_filter(EntityType type);
  void add_special_value(const QString& name, const QString& text);

  QString get_selected_name() const;
  void set_selected_name(const QString& name);

public slots:

  void build();

private:

  using SpecialValue = std::pair<QString, QString>;

  const MapModel* map;                       /**< The map from where to show entities. */
  std::vector<SpecialValue> special_values;  /**< Non-entity values added to the list. */
  bool filtered_by_entity_type;              /**< Whether only one type of entity is proposed. */
  EntityType entity_type_filter;             /**< The type of entity to only show. */

};

#endif
