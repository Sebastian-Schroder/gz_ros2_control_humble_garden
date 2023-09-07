// Copyright 2021 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef IGN_ROS2_CONTROL__IGN_ROS2_CONTROL_PLUGIN_HPP_
#define IGN_ROS2_CONTROL__IGN_ROS2_CONTROL_PLUGIN_HPP_

#include <memory>
#include <ignition/gazebo/System.hh>
#if GZ_PLUGIN_VER == 1
  namespace SIM_NAMESPACE=ignition::gazebo;
#else 
  namespace SIM_NAMESPACE=gz::sim;
#endif





namespace ign_ros2_control
{
// Forward declarations.
class IgnitionROS2ControlPluginPrivate;

class IgnitionROS2ControlPlugin
  : public SIM_NAMESPACE::System,
  public SIM_NAMESPACE::ISystemConfigure,
  public SIM_NAMESPACE::ISystemPreUpdate,
  public SIM_NAMESPACE::ISystemPostUpdate
{
public:
  /// \brief Constructor
  IgnitionROS2ControlPlugin();

  /// \brief Destructor
  ~IgnitionROS2ControlPlugin() override;

  // Documentation inherited
  void Configure(
    const SIM_NAMESPACE::Entity & _entity,
    const std::shared_ptr<const sdf::Element> & _sdf,
    SIM_NAMESPACE::EntityComponentManager & _ecm,
    SIM_NAMESPACE::EventManager & _eventMgr) override;

  // Documentation inherited
  void PreUpdate(
    const SIM_NAMESPACE::UpdateInfo & _info,
    SIM_NAMESPACE::EntityComponentManager & _ecm) override;

  void PostUpdate(
    const SIM_NAMESPACE::UpdateInfo & _info,
    const SIM_NAMESPACE::EntityComponentManager & _ecm) override;

private:
  /// \brief Private data pointer.
  std::unique_ptr<IgnitionROS2ControlPluginPrivate> dataPtr;
};
}  // namespace ign_ros2_control

#endif  // IGN_ROS2_CONTROL__IGN_ROS2_CONTROL_PLUGIN_HPP_
