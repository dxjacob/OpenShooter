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

GameState::GameState()
{
    playerPosition_ = Point3(0,0,0);
    totalTime_ = lastSpawnTime_ = 0;
}

void GameState::Shoot()
{
    projectiles_.push_back(Point3(0,0,0));
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
    vector<Point3>::iterator it;
    for (it = projectiles_.begin(); it != projectiles_.end();)
    {
        Point3& position = *it;
        
        // update position 
        position += Vector3(0,0,ProjectileSpeed*dt);
        
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

bool didCollide(Point3 point0, float radius0, Point3 point1, float radius1)
{
    float distanceSquared = distSqr(point0, point1);
    float radius = radius0 + radius1;
    return distanceSquared < radius * radius;
}
    
void GameState::HandleCollision()
{
    vector<Point3>::iterator enemyIterator;
    for (enemyIterator = enemies_.begin(); enemyIterator != enemies_.end();)
    {
        bool collision = false;
        vector<Point3>::iterator projectileIterator;
        for(projectileIterator = projectiles_.begin(); projectileIterator != projectiles_.end(); )
        {
            collision = didCollide(*projectileIterator, ProjectileRadius, *enemyIterator, EnemyRadius);
            
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
