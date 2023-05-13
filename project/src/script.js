import './styles.css'
import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'

// Debug


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

// Geometry
const points = []
const galaxySize = 1000

// Temp avariables to assign new values inside loop
var norm, theta, phi, thetaVar, distance;

// First arm
for (let i = 0; i < 1000; i++) {
    // Norm increments from 0 to 1
    norm = i / 1000;

    // Random variation to theta [-0.5, 0.5]
    thetaVar = THREE.Math.randFloatSpread(0.5);

    // Theta goes from 0 to Math.PI (+ random variation)
    theta = (norm * 4) + thetaVar;

    // Phi stays close to 0 to create galaxy ecliptic plane
    phi = THREE.Math.randFloatSpread(0.2);

    // Distance grows from 0 to galaxySize
    distance = norm * galaxySize;

    // Generate spiral arms
    points.push(new THREE.Vector3(
        distance * Math.sin(theta) * Math.cos(phi) * 1,
        distance * Math.sin(theta) * Math.sin(phi) * 1,
        distance * Math.cos(theta) * 1
    ));
}

// Second Spiral
for (let i = 0; i < 1000; i++) {
    // Norm increments from 0 to 1
    norm = i / 1000;

    // Random variation to theta [-0.5, 0.5]
    thetaVar = THREE.Math.randFloatSpread(0.5);

    // Theta goes from 0 to Math.PI (+ random variation)
    theta = (norm * 4) + thetaVar;

    // Phi stays close to 0 to create galaxy ecliptic plane
    phi = THREE.Math.randFloatSpread(0.2);

    // Distance grows from 0 to galaxySize
    distance = norm * galaxySize;

    // Generate spiral arms
    points.push(new THREE.Vector3(
        distance * Math.sin(theta) * Math.cos(phi) * -1,
        distance * Math.sin(theta) * Math.sin(phi) * -1,
        distance * Math.cos(theta) * -1
    ));
}

// Second Spiral
for (let i = 0; i < 1000; i++) {
    // Norm increments from 0 to 1
    norm = i / 1000;

    // Random variation to theta [-0.5, 0.5]
    thetaVar = THREE.Math.randFloatSpread(0.5);

    // Theta goes from 0 to Math.PI (+ random variation)
    theta = (norm * 4) + thetaVar;

    // Phi stays close to 0 to create galaxy ecliptic plane
    phi = THREE.Math.randFloatSpread(0.2);

    // Distance grows from 0 to galaxySize
    distance = norm * galaxySize;

    // Generate spiral arms
    points.push(new THREE.Vector3(
        distance * Math.sin(theta) * Math.cos(phi) * -0.5,
        distance * Math.sin(theta) * Math.sin(phi) * -0.5,
        distance * Math.cos(theta) * -0.5
    ));
}

// Second Spiral
for (let i = 0; i < 1000; i++) {
    // Norm increments from 0 to 1
    norm = i / 1000;

    // Random variation to theta [-0.5, 0.5]
    thetaVar = THREE.Math.randFloatSpread(0.5);

    // Theta goes from 0 to Math.PI (+ random variation)
    theta = (norm * 4) + thetaVar;

    // Phi stays close to 0 to create galaxy ecliptic plane
    phi = THREE.Math.randFloatSpread(0.2);

    // Distance grows from 0 to galaxySize
    distance = norm * galaxySize;

    // Generate spiral arms
    points.push(new THREE.Vector3(
        distance * Math.sin(theta) * Math.cos(phi) * 0.5,
        distance * Math.sin(theta) * Math.sin(phi) * 0.5,
        distance * Math.cos(theta) * 0.5
    ));
}

// Geometry
let geometry = new THREE.BufferGeometry().setFromPoints(points)

// Loading a custom texture
// const texture = new
// THREE.TextureLoader().load('./star.png')
// const loadedTexture = new THREE.PointsMaterial({ map:texture })

// Creating a shader
var material = new THREE.ShaderMaterial({
    uniforms: {
      color1: {
        value: new THREE.Color("red")
      },
      color2: {
        value: new THREE.Color("purple")
      }
    },
    vertexShader: `
      varying vec2 vUv;

      void main() {
        vUv = uv;
        gl_PointSize = 100.;
        gl_Position = projectionMatrix * modelViewMatrix * vec4(position,1.0);
      }
    `,
    fragmentShader: `
      uniform vec3 color1;
      uniform vec3 color2;

      varying vec2 vUv;

      void main() {

        gl_FragColor = vec4(mix(color1, color2, vUv.y), 1.0);
      }
    `
  });

const spiralGalaxy = new THREE.Points(geometry, new THREE.PointsMaterial(), material)
scene.add(spiralGalaxy)

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
const camera = new THREE.PerspectiveCamera(50, sizes.width / sizes.height, 0.1, 5000)
camera.position.x = 0
camera.position.y = 1000
camera.position.z = 1700
scene.add(camera)

// Controls
const controls = new OrbitControls(camera, canvas)
controls.enableDamping = true
controls.autoRotate = true
controls.autoRotateSpeed = 5.0

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

    // Update Orbital Controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()