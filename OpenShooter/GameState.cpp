#include "GameState.h"
using namespace std;

const float ProjectileRemoveDistance = 50;
const float ProjectileSpeed = 4;
const float ProjectileRadius = 0.2;

const float EnemeyRemoveDistance = -10;
const float EnemySpawnTime = 10;
const float EnemySpawnDistance = 30;
const float EnemySpawnRange= 3;
const float EnemySpeed = 0.5;
const float EnemyRadius = 0.3;

const float ViewRotationScale = 0.2;

GameState::GameState()
{
    playerDirection_ = 0;
    playerPosition_ = Point3(0,0,-5);
    totalTime_ = lastSpawnTime_ = 0;
}

void GameState::Shoot()
{
    Vector3 direction(sin(playerDirection_), 0, cos(playerDirection_));
    projectiles_.push_back(Projectile(playerPosition_, direction));
}

void GameState::RotatePlayer(float angle)
{
    playerDirection_ = -angle * ViewRotationScale;

}

void GameState::Update(float dt)
{
    totalTime_ += dt;
    
    UpdateProjectiles(dt);
    UpdateEnemies(dt);
    SpawnEnemies();
    HandleCollision();
}

void GameState::UpdateProjectiles(float dt)
{
    vector<Projectile>::iterator it;
    for (it = projectiles_.begin(); it != projectiles_.end();)
    {
        Point3& position = it->position;
        
        // update position 
        position += ProjectileSpeed*dt*it->direction;
        
        // remove
        if (position.getZ() > ProjectileRemoveDistance)
            projectiles_.erase(it);
            else
                it++;
    }
}

void GameState::UpdateEnemies(float dt)
{
    vector<Point3>::iterator it;
    for (it = enemies_.begin(); it != enemies_.end();)
    {
        Point3& position = *it;
        
        // update position 
        position -= Vector3(0,0,EnemySpeed*dt);
        
        // remove
        if (position.getZ() < EnemeyRemoveDistance)
            enemies_.erase(it);
        else
            it++;
    }
}

void GameState::SpawnEnemies()
{
    if (totalTime_ - lastSpawnTime_ > EnemySpawnTime)
    {
        lastSpawnTime_ = totalTime_;
        
        float x = (rand()/(float)RAND_MAX - 0.5) * EnemySpawnRange;
        enemies_.push_back(Point3(x, 0, EnemySpawnDistance));
    }  
}

bool didSpheresCollide(Point3 pointA, float radiusA, Point3 pointB, float radiusB)
{
    float distanceSquared = distSqr(pointA, pointB);
    float radius = radiusA + radiusB;
    return distanceSquared < radius * radius;
}
    
void GameState::HandleCollision()
{
    vector<Point3>::iterator enemyIterator;
    for (enemyIterator = enemies_.begin(); enemyIterator != enemies_.end();)
    {
        bool collision = false;
        vector<Projectile>::iterator projectileIterator;
        for(projectileIterator = projectiles_.begin(); projectileIterator != projectiles_.end(); )
        {
            collision = didSpheresCollide(projectileIterator->position, ProjectileRadius, *enemyIterator, EnemyRadius);
            
            // remove projectile
            if (collision)
            {
                projectiles_.erase(projectileIterator);
                break;
            }
            else
                projectileIterator++;
        }
        
        // remove enemy
        if (collision)
            enemies_.erase(enemyIterator);
        else
            enemyIterator++;
    }
}
