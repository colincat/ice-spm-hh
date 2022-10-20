//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.6
//
// <auto-generated>
//
// Generated from file `Session.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

import Foundation
import Ice
import PromiseKit
import Glacier2

/// Traits for Slice interface `Session`.
public struct SessionTraits: Ice.SliceTraits {
    public static let staticIds = ["::Glacier2::Session", "::Ice::Object", "::IceGrid::Session"]
    public static let staticId = "::IceGrid::Session"
}

/// A session object is used by IceGrid clients to allocate and
/// release objects. Client sessions are created either via the
/// Registry object or via the registry client SessionManager
/// object.
///
/// SessionPrx Methods:
///
///  - keepAlive: Keep the session alive.
///
///  - keepAliveAsync: Keep the session alive.
///
///  - allocateObjectById: Allocate an object.
///
///  - allocateObjectByIdAsync: Allocate an object.
///
///  - allocateObjectByType: Allocate an object with the given type.
///
///  - allocateObjectByTypeAsync: Allocate an object with the given type.
///
///  - releaseObject: Release an object that was allocated using allocateObjectById or allocateObjectByType.
///
///  - releaseObjectAsync: Release an object that was allocated using allocateObjectById or allocateObjectByType.
///
///  - setAllocationTimeout: Set the allocation timeout.
///
///  - setAllocationTimeoutAsync: Set the allocation timeout.
public protocol SessionPrx: Glacier2.SessionPrx {}

private final class SessionPrxI: Ice.ObjectPrxI, SessionPrx {
    public override class func ice_staticId() -> Swift.String {
        return SessionTraits.staticId
    }
}

/// Casts a proxy to the requested type. This call contacts the server and verifies that the object
/// implements this type.
///
/// It will throw a local exception if a communication error occurs. You can optionally supply a
/// facet name and a context map.
///
/// - parameter prx: `Ice.ObjectPrx` - The proxy to be cast.
///
/// - parameter type: `SessionPrx.Protocol` - The proxy type to cast to.
///
/// - parameter facet: `String` - The optional name of the desired facet.
///
/// - parameter context: `Ice.Context` The optional context dictionary for the remote invocation.
///
/// - returns: `SessionPrx` - A proxy with the requested type or nil if the objet does not
///   support this type.
///
/// - throws: `Ice.LocalException` if a communication error occurs.
public func checkedCast(prx: Ice.ObjectPrx, type: SessionPrx.Protocol, facet: Swift.String? = nil, context: Ice.Context? = nil) throws -> SessionPrx? {
    return try SessionPrxI.checkedCast(prx: prx, facet: facet, context: context) as SessionPrxI?
}

/// Downcasts the given proxy to this type without contacting the remote server.
///
/// - parameter prx: `Ice.ObjectPrx` The proxy to be cast.
///
/// - parameter type: `SessionPrx.Protocol` - The proxy type to cast to.
///
/// - parameter facet: `String` - The optional name of the desired facet
///
/// - returns: `SessionPrx` - A proxy with the requested type
public func uncheckedCast(prx: Ice.ObjectPrx, type: SessionPrx.Protocol, facet: Swift.String? = nil) -> SessionPrx {
    return SessionPrxI.uncheckedCast(prx: prx, facet: facet) as SessionPrxI
}

/// Returns the Slice type id of the interface or class associated with this proxy type.
///
/// parameter type: `SessionPrx.Protocol` -  The proxy type to retrieve the type id.
///
/// returns: `String` - The type id of the interface or class associated with this proxy type.
public func ice_staticId(_ type: SessionPrx.Protocol) -> Swift.String {
    return SessionTraits.staticId
}

/// Extension to `Ice.InputStream` class to support reading proxy of type
/// `SessionPrx`.
public extension Ice.InputStream {
    /// Extracts a proxy from the stream. The stream must have been initialized with a communicator.
    ///
    /// - parameter type: `SessionPrx.Protocol` - The type of the proxy to be extracted.
    ///
    /// - returns: `SessionPrx?` - The extracted proxy
    func read(_ type: SessionPrx.Protocol) throws -> SessionPrx? {
        return try read() as SessionPrxI?
    }
    /// Extracts a proxy from the stream. The stream must have been initialized with a communicator.
    ///
    /// - parameter tag: `Int32` - The numeric tag associated with the value.
    ///
    /// - parameter type: `SessionPrx.Protocol` - The type of the proxy to be extracted.
    ///
    /// - returns: `SessionPrx` - The extracted proxy.
    func read(tag: Swift.Int32, type: SessionPrx.Protocol) throws -> SessionPrx? {
        return try read(tag: tag) as SessionPrxI?
    }
}

/// A session object is used by IceGrid clients to allocate and
/// release objects. Client sessions are created either via the
/// Registry object or via the registry client SessionManager
/// object.
///
/// SessionPrx Methods:
///
///  - keepAlive: Keep the session alive.
///
///  - keepAliveAsync: Keep the session alive.
///
///  - allocateObjectById: Allocate an object.
///
///  - allocateObjectByIdAsync: Allocate an object.
///
///  - allocateObjectByType: Allocate an object with the given type.
///
///  - allocateObjectByTypeAsync: Allocate an object with the given type.
///
///  - releaseObject: Release an object that was allocated using allocateObjectById or allocateObjectByType.
///
///  - releaseObjectAsync: Release an object that was allocated using allocateObjectById or allocateObjectByType.
///
///  - setAllocationTimeout: Set the allocation timeout.
///
///  - setAllocationTimeoutAsync: Set the allocation timeout.
public extension SessionPrx {
    /// Keep the session alive. Clients should call this operation
    /// regularly to prevent the server from reaping the session.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    func keepAlive(context: Ice.Context? = nil) throws {
        try _impl._invoke(operation: "keepAlive",
                          mode: .Idempotent,
                          context: context)
    }

    /// Keep the session alive. Clients should call this operation
    /// regularly to prevent the server from reaping the session.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    ///
    /// - parameter sentOn: `Dispatch.DispatchQueue?` - Optional dispatch queue used to
    ///   dispatch the sent callback.
    ///
    /// - parameter sentFlags: `Dispatch.DispatchWorkItemFlags?` - Optional dispatch flags used
    ///   to dispatch the sent callback
    ///
    /// - parameter sent: `((Swift.Bool) -> Swift.Void)` - Optional sent callback.
    ///
    /// - returns: `PromiseKit.Promise<>` - The result of the operation
    func keepAliveAsync(context: Ice.Context? = nil, sentOn: Dispatch.DispatchQueue? = nil, sentFlags: Dispatch.DispatchWorkItemFlags? = nil, sent: ((Swift.Bool) -> Swift.Void)? = nil) -> PromiseKit.Promise<Swift.Void> {
        return _impl._invokeAsync(operation: "keepAlive",
                                  mode: .Idempotent,
                                  context: context,
                                  sentOn: sentOn,
                                  sentFlags: sentFlags,
                                  sent: sent)
    }

    /// Allocate an object. Depending on the allocation timeout, this
    /// operation might hang until the object is available or until the
    /// timeout is reached.
    ///
    /// - parameter _: `Ice.Identity` The identity of the object to allocate.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    ///
    /// - returns: `Ice.ObjectPrx?` - The proxy of the allocated object.
    ///
    /// - throws:
    ///
    ///   - AllocationException - Raised if the object can't be
    ///     allocated.
    ///
    ///   - ObjectNotRegisteredException - Raised if the object with
    ///     the given identity is not registered with the registry.
    func allocateObjectById(_ iceP_id: Ice.Identity, context: Ice.Context? = nil) throws -> Ice.ObjectPrx? {
        return try _impl._invoke(operation: "allocateObjectById",
                                 mode: .Normal,
                                 write: { ostr in
                                     ostr.write(iceP_id)
                                 },
                                 read: { istr in
                                     let iceP_returnValue: Ice.ObjectPrx? = try istr.read(Ice.ObjectPrx.self)
                                     return iceP_returnValue
                                 },
                                 userException:{ ex in
                                     do  {
                                         throw ex
                                     } catch let error as AllocationException {
                                         throw error
                                     } catch let error as ObjectNotRegisteredException {
                                         throw error
                                     } catch is Ice.UserException {}
                                 },
                                 context: context)
    }

    /// Allocate an object. Depending on the allocation timeout, this
    /// operation might hang until the object is available or until the
    /// timeout is reached.
    ///
    /// - parameter _: `Ice.Identity` The identity of the object to allocate.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    ///
    /// - parameter sentOn: `Dispatch.DispatchQueue?` - Optional dispatch queue used to
    ///   dispatch the sent callback.
    ///
    /// - parameter sentFlags: `Dispatch.DispatchWorkItemFlags?` - Optional dispatch flags used
    ///   to dispatch the sent callback
    ///
    /// - parameter sent: `((Swift.Bool) -> Swift.Void)` - Optional sent callback.
    ///
    /// - returns: `PromiseKit.Promise<Ice.ObjectPrx?>` - The result of the operation
    func allocateObjectByIdAsync(_ iceP_id: Ice.Identity, context: Ice.Context? = nil, sentOn: Dispatch.DispatchQueue? = nil, sentFlags: Dispatch.DispatchWorkItemFlags? = nil, sent: ((Swift.Bool) -> Swift.Void)? = nil) -> PromiseKit.Promise<Ice.ObjectPrx?> {
        return _impl._invokeAsync(operation: "allocateObjectById",
                                  mode: .Normal,
                                  write: { ostr in
                                      ostr.write(iceP_id)
                                  },
                                  read: { istr in
                                      let iceP_returnValue: Ice.ObjectPrx? = try istr.read(Ice.ObjectPrx.self)
                                      return iceP_returnValue
                                  },
                                  userException:{ ex in
                                      do  {
                                          throw ex
                                      } catch let error as AllocationException {
                                          throw error
                                      } catch let error as ObjectNotRegisteredException {
                                          throw error
                                      } catch is Ice.UserException {}
                                  },
                                  context: context,
                                  sentOn: sentOn,
                                  sentFlags: sentFlags,
                                  sent: sent)
    }

    /// Allocate an object with the given type. Depending on the
    /// allocation timeout, this operation can block until an object
    /// becomes available or until the timeout is reached.
    ///
    /// - parameter _: `Swift.String` The type of the object.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    ///
    /// - returns: `Ice.ObjectPrx?` - The proxy of the allocated object.
    ///
    /// - throws:
    ///
    ///   - AllocationException - Raised if the object could not be allocated.
    func allocateObjectByType(_ iceP_type: Swift.String, context: Ice.Context? = nil) throws -> Ice.ObjectPrx? {
        return try _impl._invoke(operation: "allocateObjectByType",
                                 mode: .Normal,
                                 write: { ostr in
                                     ostr.write(iceP_type)
                                 },
                                 read: { istr in
                                     let iceP_returnValue: Ice.ObjectPrx? = try istr.read(Ice.ObjectPrx.self)
                                     return iceP_returnValue
                                 },
                                 userException:{ ex in
                                     do  {
                                         throw ex
                                     } catch let error as AllocationException {
                                         throw error
                                     } catch is Ice.UserException {}
                                 },
                                 context: context)
    }

    /// Allocate an object with the given type. Depending on the
    /// allocation timeout, this operation can block until an object
    /// becomes available or until the timeout is reached.
    ///
    /// - parameter _: `Swift.String` The type of the object.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    ///
    /// - parameter sentOn: `Dispatch.DispatchQueue?` - Optional dispatch queue used to
    ///   dispatch the sent callback.
    ///
    /// - parameter sentFlags: `Dispatch.DispatchWorkItemFlags?` - Optional dispatch flags used
    ///   to dispatch the sent callback
    ///
    /// - parameter sent: `((Swift.Bool) -> Swift.Void)` - Optional sent callback.
    ///
    /// - returns: `PromiseKit.Promise<Ice.ObjectPrx?>` - The result of the operation
    func allocateObjectByTypeAsync(_ iceP_type: Swift.String, context: Ice.Context? = nil, sentOn: Dispatch.DispatchQueue? = nil, sentFlags: Dispatch.DispatchWorkItemFlags? = nil, sent: ((Swift.Bool) -> Swift.Void)? = nil) -> PromiseKit.Promise<Ice.ObjectPrx?> {
        return _impl._invokeAsync(operation: "allocateObjectByType",
                                  mode: .Normal,
                                  write: { ostr in
                                      ostr.write(iceP_type)
                                  },
                                  read: { istr in
                                      let iceP_returnValue: Ice.ObjectPrx? = try istr.read(Ice.ObjectPrx.self)
                                      return iceP_returnValue
                                  },
                                  userException:{ ex in
                                      do  {
                                          throw ex
                                      } catch let error as AllocationException {
                                          throw error
                                      } catch is Ice.UserException {}
                                  },
                                  context: context,
                                  sentOn: sentOn,
                                  sentFlags: sentFlags,
                                  sent: sent)
    }

    /// Release an object that was allocated using allocateObjectById or
    /// allocateObjectByType.
    ///
    /// - parameter _: `Ice.Identity` The identity of the object to release.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    ///
    /// - throws:
    ///
    ///   - AllocationException - Raised if the given object can't be
    ///     released. This might happen if the object isn't allocatable or
    ///     isn't allocated by the session.
    ///
    ///   - ObjectNotRegisteredException - Raised if the object with
    ///     the given identity is not registered with the registry.
    func releaseObject(_ iceP_id: Ice.Identity, context: Ice.Context? = nil) throws {
        try _impl._invoke(operation: "releaseObject",
                          mode: .Normal,
                          write: { ostr in
                              ostr.write(iceP_id)
                          },
                          userException:{ ex in
                              do  {
                                  throw ex
                              } catch let error as AllocationException {
                                  throw error
                              } catch let error as ObjectNotRegisteredException {
                                  throw error
                              } catch is Ice.UserException {}
                          },
                          context: context)
    }

    /// Release an object that was allocated using allocateObjectById or
    /// allocateObjectByType.
    ///
    /// - parameter _: `Ice.Identity` The identity of the object to release.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    ///
    /// - parameter sentOn: `Dispatch.DispatchQueue?` - Optional dispatch queue used to
    ///   dispatch the sent callback.
    ///
    /// - parameter sentFlags: `Dispatch.DispatchWorkItemFlags?` - Optional dispatch flags used
    ///   to dispatch the sent callback
    ///
    /// - parameter sent: `((Swift.Bool) -> Swift.Void)` - Optional sent callback.
    ///
    /// - returns: `PromiseKit.Promise<>` - The result of the operation
    func releaseObjectAsync(_ iceP_id: Ice.Identity, context: Ice.Context? = nil, sentOn: Dispatch.DispatchQueue? = nil, sentFlags: Dispatch.DispatchWorkItemFlags? = nil, sent: ((Swift.Bool) -> Swift.Void)? = nil) -> PromiseKit.Promise<Swift.Void> {
        return _impl._invokeAsync(operation: "releaseObject",
                                  mode: .Normal,
                                  write: { ostr in
                                      ostr.write(iceP_id)
                                  },
                                  userException:{ ex in
                                      do  {
                                          throw ex
                                      } catch let error as AllocationException {
                                          throw error
                                      } catch let error as ObjectNotRegisteredException {
                                          throw error
                                      } catch is Ice.UserException {}
                                  },
                                  context: context,
                                  sentOn: sentOn,
                                  sentFlags: sentFlags,
                                  sent: sent)
    }

    /// Set the allocation timeout. If no objects are available for an
    /// allocation request, a call to allocateObjectById or
    /// allocateObjectByType will block for the duration of this
    /// timeout.
    ///
    /// - parameter _: `Swift.Int32` The timeout in milliseconds.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    func setAllocationTimeout(_ iceP_timeout: Swift.Int32, context: Ice.Context? = nil) throws {
        try _impl._invoke(operation: "setAllocationTimeout",
                          mode: .Idempotent,
                          write: { ostr in
                              ostr.write(iceP_timeout)
                          },
                          context: context)
    }

    /// Set the allocation timeout. If no objects are available for an
    /// allocation request, a call to allocateObjectById or
    /// allocateObjectByType will block for the duration of this
    /// timeout.
    ///
    /// - parameter _: `Swift.Int32` The timeout in milliseconds.
    ///
    /// - parameter context: `Ice.Context` - Optional request context.
    ///
    /// - parameter sentOn: `Dispatch.DispatchQueue?` - Optional dispatch queue used to
    ///   dispatch the sent callback.
    ///
    /// - parameter sentFlags: `Dispatch.DispatchWorkItemFlags?` - Optional dispatch flags used
    ///   to dispatch the sent callback
    ///
    /// - parameter sent: `((Swift.Bool) -> Swift.Void)` - Optional sent callback.
    ///
    /// - returns: `PromiseKit.Promise<>` - The result of the operation
    func setAllocationTimeoutAsync(_ iceP_timeout: Swift.Int32, context: Ice.Context? = nil, sentOn: Dispatch.DispatchQueue? = nil, sentFlags: Dispatch.DispatchWorkItemFlags? = nil, sent: ((Swift.Bool) -> Swift.Void)? = nil) -> PromiseKit.Promise<Swift.Void> {
        return _impl._invokeAsync(operation: "setAllocationTimeout",
                                  mode: .Idempotent,
                                  write: { ostr in
                                      ostr.write(iceP_timeout)
                                  },
                                  context: context,
                                  sentOn: sentOn,
                                  sentFlags: sentFlags,
                                  sent: sent)
    }
}


/// Dispatcher for `Session` servants.
public struct SessionDisp: Ice.Disp {
    public let servant: Session
    private static let defaultObject = Ice.ObjectI<SessionTraits>()

    public init(_ servant: Session) {
        self.servant = servant
    }

    public func dispatch(request: Ice.Request, current: Ice.Current) throws -> PromiseKit.Promise<Ice.OutputStream>? {
        request.startOver()
        switch current.operation {
        case "allocateObjectById":
            return try servant._iceD_allocateObjectById(incoming: request, current: current)
        case "allocateObjectByType":
            return try servant._iceD_allocateObjectByType(incoming: request, current: current)
        case "destroy":
            return try servant._iceD_destroy(incoming: request, current: current)
        case "ice_id":
            return try (servant as? Object ?? SessionDisp.defaultObject)._iceD_ice_id(incoming: request, current: current)
        case "ice_ids":
            return try (servant as? Object ?? SessionDisp.defaultObject)._iceD_ice_ids(incoming: request, current: current)
        case "ice_isA":
            return try (servant as? Object ?? SessionDisp.defaultObject)._iceD_ice_isA(incoming: request, current: current)
        case "ice_ping":
            return try (servant as? Object ?? SessionDisp.defaultObject)._iceD_ice_ping(incoming: request, current: current)
        case "keepAlive":
            return try servant._iceD_keepAlive(incoming: request, current: current)
        case "releaseObject":
            return try servant._iceD_releaseObject(incoming: request, current: current)
        case "setAllocationTimeout":
            return try servant._iceD_setAllocationTimeout(incoming: request, current: current)
        default:
            throw Ice.OperationNotExistException(id: current.id, facet: current.facet, operation: current.operation)
        }
    }
}

/// A session object is used by IceGrid clients to allocate and
/// release objects. Client sessions are created either via the
/// Registry object or via the registry client SessionManager
/// object.
public protocol Session: Glacier2.Session {
    /// Keep the session alive. Clients should call this operation
    /// regularly to prevent the server from reaping the session.
    ///
    /// - parameter current: `Ice.Current` - The Current object for the dispatch.
    func keepAlive(current: Ice.Current) throws

    /// Allocate an object. Depending on the allocation timeout, this
    /// operation might hang until the object is available or until the
    /// timeout is reached.
    ///
    /// - parameter id: `Ice.Identity` The identity of the object to allocate.
    ///
    /// - parameter current: `Ice.Current` - The Current object for the dispatch.
    ///
    /// - returns: `PromiseKit.Promise<Ice.ObjectPrx?>` - The result of the operation
    func allocateObjectByIdAsync(id: Ice.Identity, current: Ice.Current) -> PromiseKit.Promise<Ice.ObjectPrx?>

    /// Allocate an object with the given type. Depending on the
    /// allocation timeout, this operation can block until an object
    /// becomes available or until the timeout is reached.
    ///
    /// - parameter type: `Swift.String` The type of the object.
    ///
    /// - parameter current: `Ice.Current` - The Current object for the dispatch.
    ///
    /// - returns: `PromiseKit.Promise<Ice.ObjectPrx?>` - The result of the operation
    func allocateObjectByTypeAsync(type: Swift.String, current: Ice.Current) -> PromiseKit.Promise<Ice.ObjectPrx?>

    /// Release an object that was allocated using allocateObjectById or
    /// allocateObjectByType.
    ///
    /// - parameter id: `Ice.Identity` The identity of the object to release.
    ///
    /// - parameter current: `Ice.Current` - The Current object for the dispatch.
    ///
    /// - throws:
    ///
    ///   - AllocationException - Raised if the given object can't be
    ///     released. This might happen if the object isn't allocatable or
    ///     isn't allocated by the session.
    ///
    ///   - ObjectNotRegisteredException - Raised if the object with
    ///     the given identity is not registered with the registry.
    func releaseObject(id: Ice.Identity, current: Ice.Current) throws

    /// Set the allocation timeout. If no objects are available for an
    /// allocation request, a call to allocateObjectById or
    /// allocateObjectByType will block for the duration of this
    /// timeout.
    ///
    /// - parameter timeout: `Swift.Int32` The timeout in milliseconds.
    ///
    /// - parameter current: `Ice.Current` - The Current object for the dispatch.
    func setAllocationTimeout(timeout: Swift.Int32, current: Ice.Current) throws
}

/// A session object is used by IceGrid clients to allocate and
/// release objects. Client sessions are created either via the
/// Registry object or via the registry client SessionManager
/// object.
///
/// Session Methods:
///
///  - keepAlive: Keep the session alive.
///
///  - allocateObjectById: Allocate an object.
///
///  - allocateObjectByType: Allocate an object with the given type.
///
///  - releaseObject: Release an object that was allocated using allocateObjectById or allocateObjectByType.
///
///  - setAllocationTimeout: Set the allocation timeout.
public extension Session {
    func _iceD_keepAlive(incoming inS: Ice.Incoming, current: Ice.Current) throws -> PromiseKit.Promise<Ice.OutputStream>? {
        try inS.readEmptyParams()

        try self.keepAlive(current: current)

        return inS.setResult()
    }

    func _iceD_allocateObjectById(incoming inS: Ice.Incoming, current: Ice.Current) throws -> PromiseKit.Promise<Ice.OutputStream>? {
        let iceP_id: Ice.Identity = try inS.read { istr in
            let iceP_id: Ice.Identity = try istr.read()
            return iceP_id
        }

        return inS.setResultPromise(allocateObjectByIdAsync(id: iceP_id, current: current)) { (ostr, retVals) in
            let iceP_returnValue = retVals
            ostr.write(iceP_returnValue)
        }
    }

    func _iceD_allocateObjectByType(incoming inS: Ice.Incoming, current: Ice.Current) throws -> PromiseKit.Promise<Ice.OutputStream>? {
        let iceP_type: Swift.String = try inS.read { istr in
            let iceP_type: Swift.String = try istr.read()
            return iceP_type
        }

        return inS.setResultPromise(allocateObjectByTypeAsync(type: iceP_type, current: current)) { (ostr, retVals) in
            let iceP_returnValue = retVals
            ostr.write(iceP_returnValue)
        }
    }

    func _iceD_releaseObject(incoming inS: Ice.Incoming, current: Ice.Current) throws -> PromiseKit.Promise<Ice.OutputStream>? {
        let iceP_id: Ice.Identity = try inS.read { istr in
            let iceP_id: Ice.Identity = try istr.read()
            return iceP_id
        }

        try self.releaseObject(id: iceP_id, current: current)

        return inS.setResult()
    }

    func _iceD_setAllocationTimeout(incoming inS: Ice.Incoming, current: Ice.Current) throws -> PromiseKit.Promise<Ice.OutputStream>? {
        let iceP_timeout: Swift.Int32 = try inS.read { istr in
            let iceP_timeout: Swift.Int32 = try istr.read()
            return iceP_timeout
        }

        try self.setAllocationTimeout(timeout: iceP_timeout, current: current)

        return inS.setResult()
    }
}
