#include <queue>

#include "../Public/StraightSKeletonBuilder.h"
#include "../Public/Event.h"
#include "../Public/Vertex.h"

typedef std::priority_queue<Event, std::vector<Event>, Event::PriorityComparison> EventQueue;

static std::vector<Event> DequeueTopEvents(const EventQueue& eventQueue)
{
    return { };
}

static void EnqueueEvents(const EventQueue& eventQueue, const std::vector<Event>& newEvents)
{
    return;
}

std::vector<Bone> StraightSkeletonBuilder::Skeletonize(const Polygon& polygon)
{
    std::vector<Bone> skeleton;

    SetLAV SLAV { polygon };
    
    EventQueue eventQueue;

    for (const auto& LAV : SLAV.GetLAVs())
    {
        for (const auto& vertex : LAV.GetVertices())
        {
            Event newEvent { vertex.NextEvent() };
            if (newEvent.GetType() == EVENT_TYPE::NONE)
            {
                continue;
            }
            eventQueue.push(newEvent);
        }
    }
    
    while (!(eventQueue.empty() || SLAV.IsEmpty()))
    {
        std::vector<Event> firstEvents { DequeueTopEvents(eventQueue) };
        for (const auto &event : firstEvents)
        {
            Bone newBone;
            std::vector<Event> newEvents;

            switch (event.GetType())
            {
            case EVENT_TYPE::EDGE:
                if (!event.GetVertexA()->IsValid() || 
                    !event.GetVertexB()->IsValid())
                {
                    continue;
                }
                newBone = SLAV.ProcessEdgeEvent(event, newEvents);
                break;

            case EVENT_TYPE::SPLIT:
                if (!event.GetEventVertex()->IsValid())
                {
                    continue;
                }
                newBone = SLAV.ProcessSplitEvent(event, newEvents);
                break;            

            default:
                break;
            }

            EnqueueEvents(eventQueue, newEvents);
            skeleton.push_back(newBone);
        }
    }
    
    return skeleton;
}