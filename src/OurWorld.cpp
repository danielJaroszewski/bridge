#include "../include/OurWorld.hpp"
#include <iostream>

OurWorld::OurWorld(float gravityFactor_)
:gravityFactor(gravityFactor_)
{    
}

void OurWorld::addComponent(OurComponent& component_)
{
    components.push_back(&component_);
}

void OurWorld::addJoint(OurJoint& joint_)
{
    joints.push_back(&joint_);
}

/**
 * @brief Initializes components from the components vector.
 * 
 */
void OurWorld::initializeComponents()
{
    gravity = b2Vec2(0.0f, gravityFactor);
    world.SetGravity(gravity);
    for(auto i:components)
    {
        try
        {
            i->dynBody = world.CreateBody(i->getBodyDef());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}

/**
 * @brief Initializes fixtures for the created components.
 * 
 */
void OurWorld::assignFixtures()
{
    for(auto i :components)
    {
        try
        {
            i->dynBody->CreateFixture(i->getFixtureDefinition());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }     
    }
}

/**
 * @brief Initializes joints from the joint vector.
 * 
 */
void OurWorld::initializeJoints()
{
    int indexA, indexB;
    for(auto a:joints)
    {
        indexA = a->getBodyAIndex();
        indexB = a->getBodyBIndex();

        a->initializeDefinition(components[indexA]->dynBody, components[indexB]->dynBody, components[indexA]->dynBody->GetWorldCenter(),components[indexB]->dynBody->GetWorldCenter()); //raczej nie getWorldCenter()
        a->setLinearStiffness(0.0f, 1.0f);
        a->distanceJoint = (b2DistanceJoint*)world.CreateJoint(a->getDistJointDef());
    }
}

/**
 * @brief Wrapper function to easily initalize all the components, fixtures and joints.
 * 
 */
void OurWorld::initializeWorld()
{   
    initializeComponents();
    assignFixtures();
    initializeJoints();

}
/**
 * @brief Clears the world from created joints and bodies.
 * 
 */
void OurWorld::destroyB2BodiesAndJoints()
{
   for(auto a:components)
   {
       world.DestroyBody(a->dynBody);
   }
   components.clear();

   for (auto i : joints)
   {
       world.DestroyJoint(i->distanceJoint);
   }


}


OurComponent OurWorld::getComponent(int index)
{
    return *components[index];
}