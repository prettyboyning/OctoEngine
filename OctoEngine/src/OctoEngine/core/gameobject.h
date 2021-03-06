#pragma once
#include "transform.h"
#include <vector>
#include <map>
#include <string>
#include <functional>

namespace octo
{
	namespace core
	{
		class Component;
		class Camera;

		class GameObject
		{
		private:
			Transform* m_Trasnform;
			std::string* m_Name;
			std::vector<GameObject*>* m_Children;
			std::vector<Component*>* m_Components;
			bool m_Enabled;
			std::string m_Tag;
			size_t m_TagHash;

		public:
			GameObject();
			virtual ~GameObject();

			inline Transform& getTransform()
			{
				return *m_Trasnform;
			}

			const std::string& getName() const;
			void setName(std::string* name);

			void addChild(GameObject* child);
			void removeChild(GameObject* child);

			void initializeComponents();
			// add component
			void addComponent(Component* component);
			// remove component
			void removeComponent(Component* component);

			// get all children
			inline std::vector<GameObject*>& getChildren() const
			{
				return *m_Children;
			}

			// get all components
			inline std::vector<Component*>& getComponents() const
			{
				return *m_Components;
			}

			// get a specific child
			// get a specific component
			// get the number of components
			// get the number of children

			void update();
			//void render(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix);
			void render(Camera& camera);
			void setEnabled(bool state);

			inline bool isEnabled()
			{
				return m_Enabled;
			}

			void setTag(const std::string& tag);
			std::string getTag(const std::string& tag);
			bool compareTag(const std::string& tag) const;
		};
	}
}
