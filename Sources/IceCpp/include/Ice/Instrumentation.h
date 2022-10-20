//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.6
//
// <auto-generated>
//
// Generated from file `Instrumentation.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_Instrumentation_h__
#define __Ice_Instrumentation_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <Ice/EndpointF.h>
#include <Ice/ConnectionF.h>
#include <Ice/Current.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 6
#       error Ice patch level mismatch!
#   endif
#endif

#ifndef ICE_API
#   if defined(ICE_STATIC_LIBS)
#       define ICE_API /**/
#   elif defined(ICE_API_EXPORTS)
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace Ice
{


namespace Instrumentation
{

class Observer;
class ThreadObserver;
class ConnectionObserver;
class DispatchObserver;
class ChildInvocationObserver;
class RemoteObserver;
class CollocatedObserver;
class InvocationObserver;
class ObserverUpdater;
class CommunicatorObserver;

}

}

namespace Ice
{

namespace Instrumentation
{

/**
 * The thread state enumeration keeps track of the different possible
 * states of Ice threads.
 */
enum class ThreadState : unsigned char
{
    /**
     * The thread is idle.
     */
    ThreadStateIdle,
    /**
     * The thread is in use performing reads or writes for Ice
     * connections. This state is only for threads from an Ice thread
     * pool.
     */
    ThreadStateInUseForIO,
    /**
     * The thread is calling user code (servant implementation, AMI
     * callbacks). This state is only for threads from an Ice thread
     * pool.
     */
    ThreadStateInUseForUser,
    /**
     * The thread is performing other internal activities (DNS
     * lookups, timer callbacks, etc).
     */
    ThreadStateInUseForOther
};

/**
 * The state of an Ice connection.
 */
enum class ConnectionState : unsigned char
{
    /**
     * The connection is being validated.
     */
    ConnectionStateValidating,
    /**
     * The connection is holding the reception of new messages.
     */
    ConnectionStateHolding,
    /**
     * The connection is active and can send and receive messages.
     */
    ConnectionStateActive,
    /**
     * The connection is being gracefully shutdown and waits for the
     * peer to close its end of the connection.
     */
    ConnectionStateClosing,
    /**
     * The connection is closed and waits for potential dispatch to be
     * finished before being destroyed and detached from the observer.
     */
    ConnectionStateClosed
};

}

}

namespace Ice
{

namespace Instrumentation
{

/**
 * The object observer interface used by instrumented objects to
 * notify the observer of their existence.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) Observer
{
public:

    ICE_MEMBER(ICE_API) virtual ~Observer();

    /**
     * This method is called when the instrumented object is created
     * or when the observer is attached to an existing object.
     */
    virtual void attach() = 0;

    /**
     * This method is called when the instrumented object is destroyed
     * and as a result the observer detached from the object.
     */
    virtual void detach() = 0;

    /**
     * Notification of a failure.
     * @param exceptionName The name of the exception.
     */
    virtual void failed(const ::std::string& exceptionName) = 0;
};

/**
 * The thread observer interface to instrument Ice threads. This can
 * be threads from the Ice thread pool or utility threads used by the
 * Ice core.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ThreadObserver : public virtual ::Ice::Instrumentation::Observer
{
public:

    ICE_MEMBER(ICE_API) virtual ~ThreadObserver();

    /**
     * Notification of thread state change.
     * @param oldState The previous thread state.
     * @param newState The new thread state.
     */
    virtual void stateChanged(ThreadState oldState, ThreadState newState) = 0;
};

/**
 * The connection observer interface to instrument Ice connections.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ConnectionObserver : public virtual ::Ice::Instrumentation::Observer
{
public:

    ICE_MEMBER(ICE_API) virtual ~ConnectionObserver();

    /**
     * Notification of sent bytes over the connection.
     * @param num The number of bytes sent.
     */
    virtual void sentBytes(int num) = 0;

    /**
     * Notification of received bytes over the connection.
     * @param num The number of bytes received.
     */
    virtual void receivedBytes(int num) = 0;
};

/**
 * The dispatch observer to instrument servant dispatch.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) DispatchObserver : public virtual ::Ice::Instrumentation::Observer
{
public:

    ICE_MEMBER(ICE_API) virtual ~DispatchObserver();

    /**
     * Notification of a user exception.
     */
    virtual void userException() = 0;

    /**
     * Reply notification.
     * @param size The size of the reply.
     */
    virtual void reply(int size) = 0;
};

/**
 * The child invocation observer to instrument remote or collocated
 * invocations.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ChildInvocationObserver : public virtual ::Ice::Instrumentation::Observer
{
public:

    ICE_MEMBER(ICE_API) virtual ~ChildInvocationObserver();

    /**
     * Reply notification.
     * @param size The size of the reply.
     */
    virtual void reply(int size) = 0;
};

/**
 * The remote observer to instrument invocations that are sent over
 * the wire.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) RemoteObserver : public virtual ::Ice::Instrumentation::ChildInvocationObserver
{
public:

    ICE_MEMBER(ICE_API) virtual ~RemoteObserver();
};

/**
 * The collocated observer to instrument invocations that are
 * collocated.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CollocatedObserver : public virtual ::Ice::Instrumentation::ChildInvocationObserver
{
public:

    ICE_MEMBER(ICE_API) virtual ~CollocatedObserver();
};

/**
 * The invocation observer to instrument invocations on proxies. A
 * proxy invocation can either result in a collocated or remote
 * invocation. If it results in a remote invocation, a sub-observer is
 * requested for the remote invocation.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) InvocationObserver : public virtual ::Ice::Instrumentation::Observer
{
public:

    ICE_MEMBER(ICE_API) virtual ~InvocationObserver();

    /**
     * Notification of the invocation being retried.
     */
    virtual void retried() = 0;

    /**
     * Notification of a user exception.
     */
    virtual void userException() = 0;

    /**
     * Get a remote observer for this invocation.
     * @param con The connection information.
     * @param endpt The connection endpoint.
     * @param requestId The ID of the invocation.
     * @param size The size of the invocation.
     * @return The observer to instrument the remote invocation.
     */
    virtual ::std::shared_ptr<::Ice::Instrumentation::RemoteObserver> getRemoteObserver(const ::std::shared_ptr<::Ice::ConnectionInfo>& con, const ::std::shared_ptr<::Ice::Endpoint>& endpt, int requestId, int size) = 0;

    /**
     * Get a collocated observer for this invocation.
     * @param adapter The object adapter hosting the collocated Ice object.
     * @param requestId The ID of the invocation.
     * @param size The size of the invocation.
     * @return The observer to instrument the collocated invocation.
     */
    virtual ::std::shared_ptr<::Ice::Instrumentation::CollocatedObserver> getCollocatedObserver(const ::std::shared_ptr<::Ice::ObjectAdapter>& adapter, int requestId, int size) = 0;
};

/**
 * The observer updater interface. This interface is implemented by
 * the Ice run-time and an instance of this interface is provided by
 * the Ice communicator on initialization to the
 * {@link CommunicatorObserver} object set with the communicator
 * initialization data. The Ice communicator calls
 * {@link CommunicatorObserver#setObserverUpdater} to provide the observer
 * updater.
 *
 * This interface can be used by add-ins implementing the
 * {@link CommunicatorObserver} interface to update the observers of
 * connections and threads.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ObserverUpdater
{
public:

    ICE_MEMBER(ICE_API) virtual ~ObserverUpdater();

    /**
     * Update connection observers associated with each of the Ice
     * connection from the communicator and its object adapters.
     *
     * When called, this method goes through all the connections and
     * for each connection {@link CommunicatorObserver#getConnectionObserver}
     * is called. The implementation of getConnectionObserver has the
     * possibility to return an updated observer if necessary.
     */
    virtual void updateConnectionObservers() = 0;

    /**
     * Update thread observers associated with each of the Ice thread
     * from the communicator and its object adapters.
     *
     * When called, this method goes through all the threads and for
     * each thread {@link CommunicatorObserver#getThreadObserver} is
     * called. The implementation of getThreadObserver has the
     * possibility to return an updated observer if necessary.
     */
    virtual void updateThreadObservers() = 0;
};

/**
 * The communicator observer interface used by the Ice run-time to
 * obtain and update observers for its observable objects. This
 * interface should be implemented by add-ins that wish to observe Ice
 * objects in order to collect statistics. An instance of this
 * interface can be provided to the Ice run-time through the Ice
 * communicator initialization data.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CommunicatorObserver
{
public:

    ICE_MEMBER(ICE_API) virtual ~CommunicatorObserver();

    /**
     * This method should return an observer for the given endpoint
     * information and connector. The Ice run-time calls this method
     * for each connection establishment attempt.
     * @param endpt The endpoint.
     * @param connector The description of the connector. For IP
     * transports, this is typically the IP address to connect to.
     * @return The observer to instrument the connection establishment.
     */
    virtual ::std::shared_ptr<::Ice::Instrumentation::Observer> getConnectionEstablishmentObserver(const ::std::shared_ptr<::Ice::Endpoint>& endpt, const ::std::string& connector) = 0;

    /**
     * This method should return an observer for the given endpoint
     * information. The Ice run-time calls this method to resolve an
     * endpoint and obtain the list of connectors.
     *
     * For IP endpoints, this typically involves doing a DNS lookup to
     * obtain the IP addresses associated with the DNS name.
     * @param endpt The endpoint.
     * @return The observer to instrument the endpoint lookup.
     */
    virtual ::std::shared_ptr<::Ice::Instrumentation::Observer> getEndpointLookupObserver(const ::std::shared_ptr<::Ice::Endpoint>& endpt) = 0;

    /**
     * This method should return a connection observer for the given
     * connection. The Ice run-time calls this method for each new
     * connection and for all the Ice communicator connections when
     * {@link ObserverUpdater#updateConnectionObservers} is called.
     * @param c The connection information.
     * @param e The connection endpoint.
     * @param s The state of the connection.
     * @param o The old connection observer if one is already set or a
     * null reference otherwise.
     * @return The connection observer to instrument the connection.
     */
    virtual ::std::shared_ptr<::Ice::Instrumentation::ConnectionObserver> getConnectionObserver(const ::std::shared_ptr<::Ice::ConnectionInfo>& c, const ::std::shared_ptr<::Ice::Endpoint>& e, ConnectionState s, const ::std::shared_ptr<ConnectionObserver>& o) = 0;

    /**
     * This method should return a thread observer for the given
     * thread. The Ice run-time calls this method for each new thread
     * and for all the Ice communicator threads when
     * {@link ObserverUpdater#updateThreadObservers} is called.
     * @param parent The parent of the thread.
     * @param id The ID of the thread to observe.
     * @param s The state of the thread.
     * @param o The old thread observer if one is already set or a
     * null reference otherwise.
     * @return The thread observer to instrument the thread.
     */
    virtual ::std::shared_ptr<::Ice::Instrumentation::ThreadObserver> getThreadObserver(const ::std::string& parent, const ::std::string& id, ThreadState s, const ::std::shared_ptr<ThreadObserver>& o) = 0;

    /**
     * This method should return an invocation observer for the given
     * invocation. The Ice run-time calls this method for each new
     * invocation on a proxy.
     * @param prx The proxy used for the invocation.
     * @param operation The name of the invocation.
     * @param ctx The context specified by the user.
     * @return The invocation observer to instrument the invocation.
     */
    virtual ::std::shared_ptr<::Ice::Instrumentation::InvocationObserver> getInvocationObserver(const ::std::shared_ptr<::Ice::ObjectPrx>& prx, const ::std::string& operation, const ::Ice::Context& ctx) = 0;

    /**
     * This method should return a dispatch observer for the given
     * dispatch. The Ice run-time calls this method each time it
     * receives an incoming invocation to be dispatched for an Ice
     * object.
     * @param c The current object as provided to the Ice servant
     * dispatching the invocation.
     * @param size The size of the dispatch.
     * @return The dispatch observer to instrument the dispatch.
     */
    virtual ::std::shared_ptr<::Ice::Instrumentation::DispatchObserver> getDispatchObserver(const ::Ice::Current& c, int size) = 0;

    /**
     * The Ice run-time calls this method when the communicator is
     * initialized. The add-in implementing this interface can use
     * this object to get the Ice run-time to re-obtain observers for
     * observed objects.
     * @param updater The observer updater object.
     */
    virtual void setObserverUpdater(const ::std::shared_ptr<ObserverUpdater>& updater) = 0;
};

}

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

/// \cond INTERNAL
namespace Ice
{

/// \cond INTERNAL
namespace Instrumentation
{

using ObserverPtr = ::std::shared_ptr<Observer>;

using ThreadObserverPtr = ::std::shared_ptr<ThreadObserver>;

using ConnectionObserverPtr = ::std::shared_ptr<ConnectionObserver>;

using DispatchObserverPtr = ::std::shared_ptr<DispatchObserver>;

using ChildInvocationObserverPtr = ::std::shared_ptr<ChildInvocationObserver>;

using RemoteObserverPtr = ::std::shared_ptr<RemoteObserver>;

using CollocatedObserverPtr = ::std::shared_ptr<CollocatedObserver>;

using InvocationObserverPtr = ::std::shared_ptr<InvocationObserver>;

using ObserverUpdaterPtr = ::std::shared_ptr<ObserverUpdater>;

using CommunicatorObserverPtr = ::std::shared_ptr<CommunicatorObserver>;

}
/// \endcond

}
/// \endcond

#else // C++98 mapping

namespace Ice
{

namespace Instrumentation
{

class Observer;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(Observer*);
/// \endcond
typedef ::IceInternal::Handle< Observer> ObserverPtr;

class ThreadObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(ThreadObserver*);
/// \endcond
typedef ::IceInternal::Handle< ThreadObserver> ThreadObserverPtr;

class ConnectionObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(ConnectionObserver*);
/// \endcond
typedef ::IceInternal::Handle< ConnectionObserver> ConnectionObserverPtr;

class DispatchObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(DispatchObserver*);
/// \endcond
typedef ::IceInternal::Handle< DispatchObserver> DispatchObserverPtr;

class ChildInvocationObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(ChildInvocationObserver*);
/// \endcond
typedef ::IceInternal::Handle< ChildInvocationObserver> ChildInvocationObserverPtr;

class RemoteObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(RemoteObserver*);
/// \endcond
typedef ::IceInternal::Handle< RemoteObserver> RemoteObserverPtr;

class CollocatedObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(CollocatedObserver*);
/// \endcond
typedef ::IceInternal::Handle< CollocatedObserver> CollocatedObserverPtr;

class InvocationObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(InvocationObserver*);
/// \endcond
typedef ::IceInternal::Handle< InvocationObserver> InvocationObserverPtr;

class ObserverUpdater;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(ObserverUpdater*);
/// \endcond
typedef ::IceInternal::Handle< ObserverUpdater> ObserverUpdaterPtr;

class CommunicatorObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(CommunicatorObserver*);
/// \endcond
typedef ::IceInternal::Handle< CommunicatorObserver> CommunicatorObserverPtr;

}

}

namespace Ice
{

namespace Instrumentation
{

/**
 * The thread state enumeration keeps track of the different possible
 * states of Ice threads.
 */
enum ThreadState
{
    /**
     * The thread is idle.
     */
    ThreadStateIdle,
    /**
     * The thread is in use performing reads or writes for Ice
     * connections. This state is only for threads from an Ice thread
     * pool.
     */
    ThreadStateInUseForIO,
    /**
     * The thread is calling user code (servant implementation, AMI
     * callbacks). This state is only for threads from an Ice thread
     * pool.
     */
    ThreadStateInUseForUser,
    /**
     * The thread is performing other internal activities (DNS
     * lookups, timer callbacks, etc).
     */
    ThreadStateInUseForOther
};

/**
 * The state of an Ice connection.
 */
enum ConnectionState
{
    /**
     * The connection is being validated.
     */
    ConnectionStateValidating,
    /**
     * The connection is holding the reception of new messages.
     */
    ConnectionStateHolding,
    /**
     * The connection is active and can send and receive messages.
     */
    ConnectionStateActive,
    /**
     * The connection is being gracefully shutdown and waits for the
     * peer to close its end of the connection.
     */
    ConnectionStateClosing,
    /**
     * The connection is closed and waits for potential dispatch to be
     * finished before being destroyed and detached from the observer.
     */
    ConnectionStateClosed
};

}

}

namespace Ice
{

namespace Instrumentation
{

/**
 * The object observer interface used by instrumented objects to
 * notify the observer of their existence.
 * \headerfile Ice/Ice.h
 */
class ICE_API Observer : public virtual ::Ice::LocalObject
{
public:

    typedef ObserverPtr PointerType;

    virtual ~Observer();

#ifdef ICE_CPP11_COMPILER
    Observer() = default;
    Observer(const Observer&) = default;
    Observer& operator=(const Observer&) = default;
#endif

    /**
     * This method is called when the instrumented object is created
     * or when the observer is attached to an existing object.
     */
    virtual void attach() = 0;

    /**
     * This method is called when the instrumented object is destroyed
     * and as a result the observer detached from the object.
     */
    virtual void detach() = 0;

    /**
     * Notification of a failure.
     * @param exceptionName The name of the exception.
     */
    virtual void failed(const ::std::string& exceptionName) = 0;
};

/// \cond INTERNAL
inline bool operator==(const Observer& lhs, const Observer& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const Observer& lhs, const Observer& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The thread observer interface to instrument Ice threads. This can
 * be threads from the Ice thread pool or utility threads used by the
 * Ice core.
 * \headerfile Ice/Ice.h
 */
class ICE_API ThreadObserver : virtual public Observer
{
public:

    typedef ThreadObserverPtr PointerType;

    virtual ~ThreadObserver();

#ifdef ICE_CPP11_COMPILER
    ThreadObserver() = default;
    ThreadObserver(const ThreadObserver&) = default;
    ThreadObserver& operator=(const ThreadObserver&) = default;
#endif

    /**
     * Notification of thread state change.
     * @param oldState The previous thread state.
     * @param newState The new thread state.
     */
    virtual void stateChanged(ThreadState oldState, ThreadState newState) = 0;
};

/// \cond INTERNAL
inline bool operator==(const ThreadObserver& lhs, const ThreadObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const ThreadObserver& lhs, const ThreadObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The connection observer interface to instrument Ice connections.
 * \headerfile Ice/Ice.h
 */
class ICE_API ConnectionObserver : virtual public Observer
{
public:

    typedef ConnectionObserverPtr PointerType;

    virtual ~ConnectionObserver();

#ifdef ICE_CPP11_COMPILER
    ConnectionObserver() = default;
    ConnectionObserver(const ConnectionObserver&) = default;
    ConnectionObserver& operator=(const ConnectionObserver&) = default;
#endif

    /**
     * Notification of sent bytes over the connection.
     * @param num The number of bytes sent.
     */
    virtual void sentBytes(::Ice::Int num) = 0;

    /**
     * Notification of received bytes over the connection.
     * @param num The number of bytes received.
     */
    virtual void receivedBytes(::Ice::Int num) = 0;
};

/// \cond INTERNAL
inline bool operator==(const ConnectionObserver& lhs, const ConnectionObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const ConnectionObserver& lhs, const ConnectionObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The dispatch observer to instrument servant dispatch.
 * \headerfile Ice/Ice.h
 */
class ICE_API DispatchObserver : virtual public Observer
{
public:

    typedef DispatchObserverPtr PointerType;

    virtual ~DispatchObserver();

#ifdef ICE_CPP11_COMPILER
    DispatchObserver() = default;
    DispatchObserver(const DispatchObserver&) = default;
    DispatchObserver& operator=(const DispatchObserver&) = default;
#endif

    /**
     * Notification of a user exception.
     */
    virtual void userException() = 0;

    /**
     * Reply notification.
     * @param size The size of the reply.
     */
    virtual void reply(::Ice::Int size) = 0;
};

/// \cond INTERNAL
inline bool operator==(const DispatchObserver& lhs, const DispatchObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const DispatchObserver& lhs, const DispatchObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The child invocation observer to instrument remote or collocated
 * invocations.
 * \headerfile Ice/Ice.h
 */
class ICE_API ChildInvocationObserver : virtual public Observer
{
public:

    typedef ChildInvocationObserverPtr PointerType;

    virtual ~ChildInvocationObserver();

#ifdef ICE_CPP11_COMPILER
    ChildInvocationObserver() = default;
    ChildInvocationObserver(const ChildInvocationObserver&) = default;
    ChildInvocationObserver& operator=(const ChildInvocationObserver&) = default;
#endif

    /**
     * Reply notification.
     * @param size The size of the reply.
     */
    virtual void reply(::Ice::Int size) = 0;
};

/// \cond INTERNAL
inline bool operator==(const ChildInvocationObserver& lhs, const ChildInvocationObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const ChildInvocationObserver& lhs, const ChildInvocationObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The remote observer to instrument invocations that are sent over
 * the wire.
 * \headerfile Ice/Ice.h
 */
class ICE_API RemoteObserver : virtual public ChildInvocationObserver
{
public:

    typedef RemoteObserverPtr PointerType;

    virtual ~RemoteObserver();

#ifdef ICE_CPP11_COMPILER
    RemoteObserver() = default;
    RemoteObserver(const RemoteObserver&) = default;
    RemoteObserver& operator=(const RemoteObserver&) = default;
#endif
};

/// \cond INTERNAL
inline bool operator==(const RemoteObserver& lhs, const RemoteObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const RemoteObserver& lhs, const RemoteObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The collocated observer to instrument invocations that are
 * collocated.
 * \headerfile Ice/Ice.h
 */
class ICE_API CollocatedObserver : virtual public ChildInvocationObserver
{
public:

    typedef CollocatedObserverPtr PointerType;

    virtual ~CollocatedObserver();

#ifdef ICE_CPP11_COMPILER
    CollocatedObserver() = default;
    CollocatedObserver(const CollocatedObserver&) = default;
    CollocatedObserver& operator=(const CollocatedObserver&) = default;
#endif
};

/// \cond INTERNAL
inline bool operator==(const CollocatedObserver& lhs, const CollocatedObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const CollocatedObserver& lhs, const CollocatedObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The invocation observer to instrument invocations on proxies. A
 * proxy invocation can either result in a collocated or remote
 * invocation. If it results in a remote invocation, a sub-observer is
 * requested for the remote invocation.
 * \headerfile Ice/Ice.h
 */
class ICE_API InvocationObserver : virtual public Observer
{
public:

    typedef InvocationObserverPtr PointerType;

    virtual ~InvocationObserver();

#ifdef ICE_CPP11_COMPILER
    InvocationObserver() = default;
    InvocationObserver(const InvocationObserver&) = default;
    InvocationObserver& operator=(const InvocationObserver&) = default;
#endif

    /**
     * Notification of the invocation being retried.
     */
    virtual void retried() = 0;

    /**
     * Notification of a user exception.
     */
    virtual void userException() = 0;

    /**
     * Get a remote observer for this invocation.
     * @param con The connection information.
     * @param endpt The connection endpoint.
     * @param requestId The ID of the invocation.
     * @param size The size of the invocation.
     * @return The observer to instrument the remote invocation.
     */
    virtual RemoteObserverPtr getRemoteObserver(const ::Ice::ConnectionInfoPtr& con, const ::Ice::EndpointPtr& endpt, ::Ice::Int requestId, ::Ice::Int size) = 0;

    /**
     * Get a collocated observer for this invocation.
     * @param adapter The object adapter hosting the collocated Ice object.
     * @param requestId The ID of the invocation.
     * @param size The size of the invocation.
     * @return The observer to instrument the collocated invocation.
     */
    virtual CollocatedObserverPtr getCollocatedObserver(const ::Ice::ObjectAdapterPtr& adapter, ::Ice::Int requestId, ::Ice::Int size) = 0;
};

/// \cond INTERNAL
inline bool operator==(const InvocationObserver& lhs, const InvocationObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const InvocationObserver& lhs, const InvocationObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The observer updater interface. This interface is implemented by
 * the Ice run-time and an instance of this interface is provided by
 * the Ice communicator on initialization to the
 * {@link CommunicatorObserver} object set with the communicator
 * initialization data. The Ice communicator calls
 * {@link CommunicatorObserver#setObserverUpdater} to provide the observer
 * updater.
 *
 * This interface can be used by add-ins implementing the
 * {@link CommunicatorObserver} interface to update the observers of
 * connections and threads.
 * \headerfile Ice/Ice.h
 */
class ICE_API ObserverUpdater : public virtual ::Ice::LocalObject
{
public:

    typedef ObserverUpdaterPtr PointerType;

    virtual ~ObserverUpdater();

#ifdef ICE_CPP11_COMPILER
    ObserverUpdater() = default;
    ObserverUpdater(const ObserverUpdater&) = default;
    ObserverUpdater& operator=(const ObserverUpdater&) = default;
#endif

    /**
     * Update connection observers associated with each of the Ice
     * connection from the communicator and its object adapters.
     *
     * When called, this method goes through all the connections and
     * for each connection {@link CommunicatorObserver#getConnectionObserver}
     * is called. The implementation of getConnectionObserver has the
     * possibility to return an updated observer if necessary.
     */
    virtual void updateConnectionObservers() = 0;

    /**
     * Update thread observers associated with each of the Ice thread
     * from the communicator and its object adapters.
     *
     * When called, this method goes through all the threads and for
     * each thread {@link CommunicatorObserver#getThreadObserver} is
     * called. The implementation of getThreadObserver has the
     * possibility to return an updated observer if necessary.
     */
    virtual void updateThreadObservers() = 0;
};

/// \cond INTERNAL
inline bool operator==(const ObserverUpdater& lhs, const ObserverUpdater& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const ObserverUpdater& lhs, const ObserverUpdater& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

/**
 * The communicator observer interface used by the Ice run-time to
 * obtain and update observers for its observable objects. This
 * interface should be implemented by add-ins that wish to observe Ice
 * objects in order to collect statistics. An instance of this
 * interface can be provided to the Ice run-time through the Ice
 * communicator initialization data.
 * \headerfile Ice/Ice.h
 */
class ICE_API CommunicatorObserver : public virtual ::Ice::LocalObject
{
public:

    typedef CommunicatorObserverPtr PointerType;

    virtual ~CommunicatorObserver();

#ifdef ICE_CPP11_COMPILER
    CommunicatorObserver() = default;
    CommunicatorObserver(const CommunicatorObserver&) = default;
    CommunicatorObserver& operator=(const CommunicatorObserver&) = default;
#endif

    /**
     * This method should return an observer for the given endpoint
     * information and connector. The Ice run-time calls this method
     * for each connection establishment attempt.
     * @param endpt The endpoint.
     * @param connector The description of the connector. For IP
     * transports, this is typically the IP address to connect to.
     * @return The observer to instrument the connection establishment.
     */
    virtual ObserverPtr getConnectionEstablishmentObserver(const ::Ice::EndpointPtr& endpt, const ::std::string& connector) = 0;

    /**
     * This method should return an observer for the given endpoint
     * information. The Ice run-time calls this method to resolve an
     * endpoint and obtain the list of connectors.
     *
     * For IP endpoints, this typically involves doing a DNS lookup to
     * obtain the IP addresses associated with the DNS name.
     * @param endpt The endpoint.
     * @return The observer to instrument the endpoint lookup.
     */
    virtual ObserverPtr getEndpointLookupObserver(const ::Ice::EndpointPtr& endpt) = 0;

    /**
     * This method should return a connection observer for the given
     * connection. The Ice run-time calls this method for each new
     * connection and for all the Ice communicator connections when
     * {@link ObserverUpdater#updateConnectionObservers} is called.
     * @param c The connection information.
     * @param e The connection endpoint.
     * @param s The state of the connection.
     * @param o The old connection observer if one is already set or a
     * null reference otherwise.
     * @return The connection observer to instrument the connection.
     */
    virtual ConnectionObserverPtr getConnectionObserver(const ::Ice::ConnectionInfoPtr& c, const ::Ice::EndpointPtr& e, ConnectionState s, const ConnectionObserverPtr& o) = 0;

    /**
     * This method should return a thread observer for the given
     * thread. The Ice run-time calls this method for each new thread
     * and for all the Ice communicator threads when
     * {@link ObserverUpdater#updateThreadObservers} is called.
     * @param parent The parent of the thread.
     * @param id The ID of the thread to observe.
     * @param s The state of the thread.
     * @param o The old thread observer if one is already set or a
     * null reference otherwise.
     * @return The thread observer to instrument the thread.
     */
    virtual ThreadObserverPtr getThreadObserver(const ::std::string& parent, const ::std::string& id, ThreadState s, const ThreadObserverPtr& o) = 0;

    /**
     * This method should return an invocation observer for the given
     * invocation. The Ice run-time calls this method for each new
     * invocation on a proxy.
     * @param prx The proxy used for the invocation.
     * @param operation The name of the invocation.
     * @param ctx The context specified by the user.
     * @return The invocation observer to instrument the invocation.
     */
    virtual InvocationObserverPtr getInvocationObserver(const ::Ice::ObjectPrx& prx, const ::std::string& operation, const ::Ice::Context& ctx) = 0;

    /**
     * This method should return a dispatch observer for the given
     * dispatch. The Ice run-time calls this method each time it
     * receives an incoming invocation to be dispatched for an Ice
     * object.
     * @param c The current object as provided to the Ice servant
     * dispatching the invocation.
     * @param size The size of the dispatch.
     * @return The dispatch observer to instrument the dispatch.
     */
    virtual DispatchObserverPtr getDispatchObserver(const ::Ice::Current& c, ::Ice::Int size) = 0;

    /**
     * The Ice run-time calls this method when the communicator is
     * initialized. The add-in implementing this interface can use
     * this object to get the Ice run-time to re-obtain observers for
     * observed objects.
     * @param updater The observer updater object.
     */
    virtual void setObserverUpdater(const ObserverUpdaterPtr& updater) = 0;
};

/// \cond INTERNAL
inline bool operator==(const CommunicatorObserver& lhs, const CommunicatorObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) == static_cast<const ::Ice::LocalObject&>(rhs);
}

inline bool operator<(const CommunicatorObserver& lhs, const CommunicatorObserver& rhs)
{
    return static_cast<const ::Ice::LocalObject&>(lhs) < static_cast<const ::Ice::LocalObject&>(rhs);
}
/// \endcond

}

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
