import './styles.css'
import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import * as dat from 'dat.gui'

// Debug
const gui = new dat.GUI()

// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

// Random function with normal distribution
const normalRandom = (mean, std) => {
    let n = 0

    for (let i = 1; i <= 12; i++) {
        n += Math.random()
    }

    return (n - 6) * std + mean
}

// Creating a tube
const geometry = new THREE.Geometry();
const galaxySize = 1000;

// Generate particles for spiral galaxy
for (let i = 0; i < 10000; i++) {
    var theta = THREE.Math.radnFloatSpread(360)
    var phi = THREE.Math.randFloatSpread(360)
    const distance = THREE.Math.rdanFloatSpread(galaxySize)

    // Change this for arms
    geometry.vertices.push(new THREE.Vector3(
        distance * Math.sin(theta) * Math.cos(phi),
        distance * Math.sin(theta) * Math.sin(phi),
        distance * Math.cos(theta) / 10
    ))
}

const spiralGalaxy = new THREE.Points(geometry, new THREE.PointsMAterial({ color: 0xffffff }))
scene.add(spiralGalaxy)
// const particlesGeometry = new THREE.BufferGeometry;
// const particlesCount = 5000;
// const posArray = new Float32Array(particlesCount * 3);

// particlesGeometry.setAttribute('position', new THREE.BufferAttribute(posArray, 3));

// // Materials
// const material = new THREE.PointsMaterial({
//     size: 0.0025
// })

// const particlesMaterial = new THREE.PointsMaterial({
//     size: 0.0025
// })

// // Mesh
// const sphere = new THREE.Points(geometry,material)
// const particlesMesh = new THREE.Points(particlesGeometry, material, particlesMaterial)
// scene.add(sphere, particlesMesh)

// Lights

const pointLight = new THREE.PointLight(0xffffff, 0.1)
pointLight.position.x = 2
pointLight.position.y = 3
pointLight.position.z = 4
scene.add(pointLight)

// Sizes

const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

window.addEventListener('resize', () =>
{
    // Update sizes
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight

    // Update camera
    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()

    // Update renderer
    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

//Camera

// Base camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)
camera.position.x = 0
camera.position.y = 0
camera.position.z = 35
scene.add(camera)

// Controls
const controls = new OrbitControls(camera, canvas)
controls.enableDamping = true

// Renderer
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
// Setting background color as an "spacey" color
renderer.setClearColor(new THREE.Color('#01010d'), 1)

// Animate
const clock = new THREE.Clock()
const tick = () =>
{
    const elapsedTime = clock.getElapsedTime()

    // Update objects
    sphere.rotation.y = .5 * elapsedTime

    // Update Orbital Controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()